// 
#include <iostream>
#include <string>

int main(void)
{
     std::string s( "the answer is 42");
     
     if (!s.contains("foo") && s.ends_with("42"))
     {
          std::printf("so long, and thanks for all the fish\n");
     }
}

