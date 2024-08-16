#include<bits/stdc++.h>

using namespace std;

int code(char c)
{
    switch (c){
        case 'B':
        case 'F':
        case 'P':
        case 'V':
            return 1;
        case 'C':
        case 'G':
        case 'J':
        case 'K':
        case 'Q':
        case 'X':
        case 'S':
        case 'Z':
            return 2;
        case 'D':
        case 'T':
            return 3;
        case 'L':
            return 4;
        case 'M':
        case 'N':
            return 5;
        case 'R':
            return 6;
        default :
            return 0;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char ch[100];
    cout<<"         NAME                     SOUNDEX CODE";
    while(gets(ch))
    {
        int prev, curr;
        int index,i;
        char result[5];

        result[0] = ch[0];
        prev = code(ch[0]);
        
        for(i=index=1; ch[i]!='\0' && index<4; i++)
        {
            curr = code(ch[i]);
            if(curr != prev && curr != 0)
            {
                result[index++] = '0'+curr;
            }
            prev = curr;
        }

        for( ;index<4;)
        {
            result[index++] = '0';
        }
        result[index] = '\0';
		printf("         %-25s%s\n",ch,result);         
    }
	puts("                   END OF OUTPUT");
    return 0;
}