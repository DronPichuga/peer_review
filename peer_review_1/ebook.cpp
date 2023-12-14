#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;

class Book
{
public:
    void Read(int user, int page)
    {
        if (page > 0)
        {
            if (readers[user] == 0) 
            {
                ++count_user;
            }
            else
            {
                readers_count[readers[user]] --;
            }

            readers[user] = page;
            readers_count[page] ++;
        }

    }
    double GetInfo(int user)
    {
        int page_number = readers[user];
        double part_users;
        if (page_number == 0) 
        {
            part_users = 0;
        }
        else if (count_user == 1) 
        {
            part_users = 1;
        }
        else {
            
            int users = std::accumulate(readers_count.begin(), (readers_count.begin() + page_number), 0);
            part_users = static_cast<double>(users) / (static_cast<double>(count_user) - 1);
           
        }
        return part_users;
    }
private:
    std::vector<int> readers = std::vector<int>(1000001, 0);

    std::vector<int> readers_count = std::vector<int>(1001, 0);

    int count_user = 0;


};


int main() 
{
    int n;
    std::cin >> n;
    int user, page;
    std::string type_request;
    Book book;

    while (n > 0)
    {
        std::cin >> type_request;
        if (type_request == "READ"s)
        {
            std::cin >> user >> page;
            book.Read(user, page);
        }
        else if (type_request == "CHEER"s)
        {
            std::cin >> user;
            std::cout << std::setprecision(6) << book.GetInfo(user) << std::endl;
        }
        --n;
    }
    
}