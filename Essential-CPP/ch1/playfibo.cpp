#include <string>
#include <iostream>

using namespace std;
 
int main() 
{
    int num_tries = 0, num_right = 0; //猜过次数，猜对次数
    char usr_rsp;
    double usr_score;
    bool go_for_it = true,next_seq = true, got_it = false;//用户再猜一次，下一次，用户是否猜对
    const int max_tries = 3; //总机会
    int next_elem = 0;

    while (next_seq == true) 
    {
        //显示数列
        while ((got_it == false) && (go_for_it == true)) 
        {
            int usr_guess;
            cin >> usr_guess;
            int max_tries = 3;
            int tries_cnt = 0;
            while (tries_cnt < max_tries)
            {
                //读取用户的答案
                if (usr_guess == next_elem)
                {
                    break;
                }
                tries_cnt++;
                
            }
            if (usr_guess == next_elem)
            {
                got_it = true;
                num_right++;
            }
            else
            {
                if(usr_rsp == 'N' || usr_rsp == 'n')
                    go_for_it = false;
            }
        }
        cout << "Try another sequence? Y/N? ";
        char try_again;
        cin >> try_again;
        if (try_again == 'N' || try_again == 'n')
        {
            next_seq = false;
        }
        
    }
    if(go_for_it == false)
        cout << "Your score for this session is "
            <<  usr_score << " Beye!\n";
    
    return 0;
}