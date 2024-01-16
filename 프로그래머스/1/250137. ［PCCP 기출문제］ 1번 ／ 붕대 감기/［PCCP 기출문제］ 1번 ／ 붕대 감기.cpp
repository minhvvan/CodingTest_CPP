#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    //t초 -> 1초마다 x만큼 회복
    //성공하면 y만큼 추가 회복(최대 체력이 있음)
    
    //피격: 붕대 취소
    //피격중 체력 회복불가
    //취소당하면 바로 다시 사용가능: 시간은 0으로 초기화
    
    //공격당하면 정해진 피해량 만큼 감소 -> 0되면 죽음
    
    //죽으면 -1, 아니면 남은체력
    
    int HealTime = bandage[0];
    int HealPerSec = bandage[1];
    int BonusHeal = bandage[2];
    
    int Currenthealth = health;
    int LastHealTime = 0;
    
    for(auto attack : attacks)
    {
        int AttackSec = attack[0];
        int Damage = attack[1];
        
        //Heal
        int HealAmount = (AttackSec - LastHealTime - 1) * HealPerSec;
        
        int BonusTimes = (AttackSec - LastHealTime - 1) / HealTime;
        HealAmount += BonusHeal * BonusTimes;
        
        LastHealTime = AttackSec;
        
        Currenthealth += HealAmount;
        if(Currenthealth > health) Currenthealth = health;
        
        //Take Damage
        Currenthealth -= Damage;
        if(Currenthealth <= 0) return -1;
    }
    
    return Currenthealth;
}