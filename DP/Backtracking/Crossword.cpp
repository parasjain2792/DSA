#include<bits/stdc++.h>
using namespace std;
void reset_Horizonal(char grid[][10],string curr_word,int row,int col,bool *helper)
{
	for(int i=0;i<curr_word.length();i++)
	{
		if(helper[i])
		{
			grid[row][col]='-';
			
		}
        col++;
	}
}
void setHorizontal(char grid[][10],string curr_word,int row,int col,bool *helper)
{
	for(int i=0;i<curr_word.length();i++)
	{
		if(grid[row][col]=='-')
		{
			grid[row][col]=curr_word[i];
			helper[i]=true;
		}
		else
		{
			helper[i]=false;
		}
		col++;
	}
}
bool valid_Horizontal(char grid[][10],string curr_word,int row,int col)
{
	for(int i=0;i<curr_word.length();i++)
	{
		if(grid[row][col]=='-' || grid[row][col]==curr_word[i])
		{
			col++;
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}
void resetVertical(char grid[][10],string curr_word,bool *helper,int row,int col)
{
	for(int i=0;i<curr_word.length();i++)
	{
		if(helper[i])
		{
			grid[row][col]='-';
			
		}
        row++;
	}
}
void setVertical(char grid[][10],string curr_word,int row,int col,bool *helper)
{
	for(int i=0;i<curr_word.length();i++)
	{
		if(grid[row][col]=='-')
		{
			grid[row][col]=curr_word[i];
			helper[i]=true;
		}
		else
		{
			helper[i]=false;
		}
		row++;
	}
}
bool valid_Vertical(char grid[][10],string curr_word,int row,int col)
{
	for(int i=0;i<curr_word.length();i++)
	{
		if(grid[row][col]=='-' || grid[row][col]==curr_word[i])
		{
			row++;
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}


bool solveCrossword(char grid[][10],vector<string> vs,int index)
{
	if(index==vs.size())
	{
        return true;
	}
    
	for(int r=0;r<10;r++)
	{
		for(int c=0;c<10;c++)
		{
			if(grid[r][c]=='-' || grid[r][c]==vs[index][0])
			{
				if(valid_Vertical(grid,vs[index],r,c))
				{
					bool helper[vs[index].size()];
					setVertical(grid,vs[index],r,c,helper);
					if(solveCrossword(grid,vs,index+1))
					{
						return true;
					}
					resetVertical(grid,vs[index],helper,r,c);
				}
                
				if(valid_Horizontal(grid,vs[index],r,c))
				{
					bool helper[vs[index].size()];
					setHorizontal(grid,vs[index],r,c,helper);
					if(solveCrossword(grid,vs,index+1))
					{
						return true;
					}
					reset_Horizonal(grid,vs[index],r,c,helper);
				}
			}
		}
	}
}

int main()
{
	char grid[10][10];
	for(int i=0;i<10;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<s.length();j++)
		{
			grid[i][j]=s[j];
		}
	}
	string names;
	cin>>names;
	string temp="";
	vector<string> vs;
	for(int i=0;i<names.length();i++)
	{
		if(names[i]!=';')
		{
			temp=temp+names[i];
		}
		else
		{
			vs.push_back(temp);
			temp="";
		}
	}
	vs.push_back(temp);
	solveCrossword(grid,vs,0);
    for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cout<<grid[i][j];
		}
		cout<<endl;
	}
	return 0;
}
