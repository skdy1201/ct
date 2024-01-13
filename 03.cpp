#include <string>
#include <vector>
#include <list>

using namespace std;

int solution(int cacheSize, vector<string> cities) 
{
    int answer = 0; // 반환 값

    bool check = false; // bool check
  

    list<string> cache; // 도시 리스트

    if (cacheSize == 0)
    {
        for (size_t i = 0; i < cities.size(); i++)
        {
            answer += 5;
        }

        return answer;
    }


    for (size_t i = 0; i < cities.size(); ++i) //들어온 도시 배열의 사이즈 만큼 반복
    {
        string temp; // 임시 string 객체

        temp = cities[i]; // temp는 cities의 i값
        
        for (size_t i = 0; i < temp.size(); i++)
        {
            temp[i] = toupper(temp[i]);
        }
        list<string>::iterator iter = cache.begin();

        if(cache.size() != 0)
        { 
            for (; iter != cache.end(); ++iter)
            {
                if ((*iter) == temp)
                {
                    answer += 1;
                    check = true;
                    break;
                }

                
            }

            if (check == false)
            {
                answer += 5;

            }
       
        }
        else
        {
            answer += 5;
        }

       

        if(cache.size() < cacheSize)
        { 
            cache.push_front(temp);
        }
        else if(cache.size() >= cacheSize)
        {
            if (check == true)
            {
                list<string>::iterator iter2 = cache.begin();

                for (; iter2 != cache.end(); ++iter2)
                {
                    if ((*iter2) == temp)
                    {
                        cache.erase(iter2);
                        cache.push_front(temp);
                        break;
                    }
                }

            }
            else
            { 
            cache.pop_back();
            cache.push_front(temp);
            }
        }

        check = false;
    }


    return answer;
}

int main()
{
    int cachesize = 0;

    vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };

    int d = solution(cachesize, cities);

    int end = 0;

    return 0;
}