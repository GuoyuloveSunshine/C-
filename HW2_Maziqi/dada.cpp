#include <iostream>
#include <sstream>
#include <list>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <climits>
#include <bitset>

using namespace std;

/* 本次计算有多少张卡牌 */
int g_number_cnt = 0;
/* 本次计算状态数 */
int g_state_cnt = 0;
/* 最大支持计算的卡牌数。这里取16 */
const int MAX_NUMBER_COUNT  = 16;
/* 采用集合论的方法，故其实是2^n个状态 */
const int MAX_STATE_COUNT   = (1 << MAX_NUMBER_COUNT);
/* 计算24点的每个数的最大值。这里是13 */
const int MAX_NUMBER   = 13;
/* 目标值24 */
const int EXPECTION = 24;
/* 状态集合中的最大元素数值 */
const int MAX_VALUE = EXPECTION * MAX_NUMBER * MAX_NUMBER_COUNT;

struct elementNode {
    int value; //本Node的值
    int left, right; //该值由哪两个State的index计算而来
    int left_value, right_value; //这两个State中的value键值
    char opr; //运算符号
};

typedef map<int, elementNode> elementMap;

struct State {
    bitset<MAX_VALUE+10> exist;
    elementMap element_map;
};

int number[MAX_NUMBER_COUNT];
State state[MAX_STATE_COUNT];
string answer;

void StateInit();
void StateMerge(int a, int b, int x);
void Solve();
bool Output();
bool Calculate24Point();
std::string Calc24(const std::vector<unsigned char>& InputCards);
bool PrintExpression(elementNode node);
string num2Card(int num);
int card2Num(char Point);


string num2Card(int num)
{
    /* 1:A
     * 2-9:
     * 10:"10"
     * 11:"J"
     * 12:"Q"
     * 13:"K"
     */
    stringstream ssCard;

    switch (num) {
        case 1:
            return "A";
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            ssCard<<num;
            return ssCard.str();
        case 10:
            return "T";
        case 11:
            return "J";
        case 12:
            return "Q";
        case 13:
            return "K";

        default:
            break;
    }
    return "0";
}
int card2Num(char Point)
{
    /* A:1
     * 2-9:2-9
     * T:10
     * J:11
     * Q:12
     * K:13
     */

    switch (Point) {
        case 'A':
            return 1;
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return Point-'0';
        case 'T':
            return 10;
        case 'J':
            return 11;
        case 'Q':
            return 12;
        case 'K':
            return 13;
        default:
            return 0;
    }

    return 0;
}

void StateInit()
{
    elementNode node ;

    for (int i = 0; i < g_state_cnt; i++) {
        state[i].element_map.clear();
        state[i].exist.reset();
    }

    answer = "";

    for (int i = 0; i < g_number_cnt; i++) {
        node.value = number[i];
        node.left = node.right = -1;
        state[(1 << i)].element_map[node.value] = node;
        state[(1 << i)].exist[node.value] = true;
    }
}

/*
 * 合并状态集合
 *
 * 做的特殊处理：
 * 1.丢弃除不尽
 * 2.丢弃过大，不超过24*13
 * 3.-和/考虑顺序，+和*不需考虑顺序
 * 4.乘法考虑越界，越界就丢弃。
 */

void StateMerge(int a, int b, int x)
{
    elementNode node;
    elementMap::iterator i, j;

    for (i = state[a].element_map.begin(); i != state[a].element_map.end(); i++){
        for (j = state[b].element_map.begin(); j != state[b].element_map.end(); j++){

            /*
             ************************************************
             * +
             ************************************************
             */

            node.value = i->second.value + j->second.value;

            if ( (node.value <= MAX_VALUE) && (!state[x].exist[node.value]) ) {
                node.left  = a;
                node.right = b;
                node.left_value  = i->second.value;
                node.right_value = j->second.value;
                node.opr   = '+';

                state[x].element_map[node.value] = node;
                state[x].exist[node.value] = true;
            }

            /*
             ************************************************
             * *
             ************************************************
             */

            double tmp_max = double(i->second.value) * double(j->second.value);

            if (tmp_max < INT_MAX) {
                node.value = i->second.value * j->second.value;

                if ( (node.value <= MAX_VALUE) && (!state[x].exist[node.value]) ){
                    node.left  = a;
                    node.right = b;
                    node.left_value  = i->second.value;
                    node.right_value = j->second.value;
                    node.opr   = '*';
                    state[x].element_map[node.value] = node;
                    state[x].exist[node.value] = true;
                }
            }

            /*
             ************************************************
             * -
             ************************************************
             */

            if (i->second.value >= j->second.value) {
                node.value = i->second.value - j->second.value;
                node.left  = a;
                node.right = b;
                node.left_value  = i->second.value;
                node.right_value = j->second.value;
                node.opr   = '-';
            } else {
                node.value = j->second.value - i->second.value;
                node.left  = b;
                node.right = a;
                node.left_value  = j->second.value;
                node.right_value = i->second.value;
                node.opr   = '-';
            }

            if ( (node.value <= MAX_VALUE) && (!state[x].exist[node.value]) ) {
                state[x].element_map[node.value] = node;
                state[x].exist[node.value] = true;
            }

            /*
             ************************************************
             * /
             ************************************************
             */


            if ( (j->second.value != 0) && (i->second.value >= j->second.value) && (i->second.value % j->second.value == 0) )
            {
                node.value = i->second.value / j->second.value;
                node.left  = a;
                node.right = b;
                node.left_value  = i->second.value;
                node.right_value = j->second.value;
                node.opr   = '/';
            } else if ( (i->second.value != 0) && (j->second.value >= i->second.value) && (j->second.value % i->second.value == 0) )
            {
                node.value = j->second.value / i->second.value;
                node.left  = b;
                node.right = a;
                node.left_value  = j->second.value;
                node.right_value = i->second.value;
                node.opr   = '/';
            }

            if ( (node.value <= MAX_VALUE) && (!state[x].exist[node.value]) ){
                state[x].element_map[node.value] = node;
                state[x].exist[node.value] = true;
            }
        }
    }
}

void Solve()
{
    StateInit();

    for (int x = 2; x < g_state_cnt; x++) {
        for (int i = 1; i < x; i++) {
            if ( (x & i) == i ) {
                int j = x - i;
                if (i <= j) {
                    StateMerge(i, j, x);
                }
            }
        }
    }
}

bool PrintExpression(elementNode node)
{
    bool ret;

    if (node.left == -1) {
        answer = answer + num2Card(node.value);
    } else {
        elementMap::iterator iter;

        answer = answer + "(";

        iter = state[node.left].element_map.find(node.left_value);
        if (iter == state[node.left].element_map.end()) {
            return false;
        }

        ret = PrintExpression(iter->second);
        if (ret == false) {
            return ret;
        }

        answer = answer + node.opr;

        iter = state[node.right].element_map.find(node.right_value);
        if (iter == state[node.right].element_map.end()) {
            return false;
        }

        ret = PrintExpression(iter->second);
        if (ret == false) {
            return ret;
        }

        answer = answer + ")";
    }

    return true;
}

bool Output()
{
    elementMap::iterator iter;
    bool ret = false;

    elementMap& node_map = state[g_state_cnt-1].element_map;

    iter = node_map.find(EXPECTION);
    if (iter == node_map.end()) {
        cout<<"we can't fine the solution"<<endl;
        return false;
    }

    ret = PrintExpression(iter->second);
    if (ret == false) {
        return ret;
    }

    return true;
}

bool Calculate24Point()
{
    bool ret = false;
    Solve();
    ret = Output();
    return ret;
}

std::string Calc24(const std::vector<unsigned char>& InputCards)
{
    bool ret;
    size_t size = InputCards.size();

    if (size > MAX_NUMBER_COUNT) {
        return "NA";
    }

    for (int i = 0; i < size; i ++) {
        number[i] = card2Num(InputCards[i]);
    }

    g_number_cnt = (int)size;
    g_state_cnt = 1<<g_number_cnt;

    ret = Calculate24Point();
    if (ret == false) {
        return "NA";
    }
    return answer;
}


int main(){
    cout<<"Please input 4 cards:\n"<<endl;
    vector<unsigned char> cards(4);
    cin>>cards[0]>>cards[1]>>cards[2]>>cards[3];
    cout<<Calc24(cards)<<endl;
}