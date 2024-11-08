#include <bits/stdc++.h>

using namespace std;

int N;

//color: 0 black, 1 white

struct Card
{
    Card(int n, int c) : num(n), color(c) {};

    int num;
    int color;

    bool operator < (const Card& Other) const
    {
        return num < Other.num;
    }
};

struct CardPair
{
    CardPair(Card a, Card b) : A(a), B(b) {};

    Card A;
    Card B;

    bool operator < (const CardPair& Other)
    {
        Card big = A < B ? B : A;
        Card small = A < B ? A : B;

        Card Otherbig = Other.A.num < Other.B.num ? Other.B : Other.A;
        Card Othersmall = Other.A.num < Other.B.num ? Other.A : Other.B;

        int diff = abs(big.num - small.num);
        if (big.num == 15 && small.num == 1) diff = 1;
        int OtherDiff = abs(Otherbig.num - Othersmall.num);
        if (Otherbig.num == 15 && Othersmall.num == 1) OtherDiff = 1;

        if (diff == 1 && OtherDiff != 1) return true;
        else if (diff != 1 && OtherDiff == 1) return false;

        if (big.num == small.num && Otherbig.num != Othersmall.num) return true;
        else if (big.num != small.num && Otherbig.num == Othersmall.num) return false;

        if (big.color == small.color && Otherbig.color != Othersmall.color) return true;
        else if (big.color != small.color && Otherbig.color == Othersmall.color) return false;

        if (big.num == Otherbig.num)
        {
            if (small.num == Othersmall.num)
            {
                return big.color == 0;
            }

            return small.num > Othersmall.num;
        }

        return big.num > Otherbig.num;
    }

    void print()
    {
        if (A.num > 9)
        {
            A.num += 39;
        }
        char s = A.num + '0';
        char sc = A.color == 0 ? 'b' : 'w';


        if (B.num > 9)
        {
            B.num += 39;
        }
        char b = B.num + '0';
        char bc = B.color == 0 ? 'b' : 'w';

        cout << s << sc << b << bc << "\n";
    }
};

bool operator<(const CardPair& lhs, const CardPair& rhs) {
    return lhs < rhs;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(4);

    vector<CardPair> CardPairs;
    vector<Card> Cards;
    for(int i = 0 ; i < 6; i++)
    {  
        string temp;
        while (getline(cin, temp, ','))
        {
            int num = 0;
            int color = 0;

            if (temp[0] - '0' >= 10)
            {
                num = (temp[0] - '0') - 39;
            }
            else
            {
                num = temp[0] - '0';
            }

            if (temp[1] == 'w') color = 1;

            Cards.push_back({ num, color });
        }
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = i+1; j < 6; j++)
        {
            CardPairs.push_back({ Cards[i], Cards[j]});
        }
    }

    sort(CardPairs.begin(), CardPairs.end());

    for (auto itr = CardPairs.begin(); itr != CardPairs.end(); itr++)
    {
        itr->print();
    }

    return 0;
}