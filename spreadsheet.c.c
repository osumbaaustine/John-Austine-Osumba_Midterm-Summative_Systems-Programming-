#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
 
int isNumber(char str[20])
{
	int i,j,k,flag=1;
	for(i=0;str[i]!='\0';i++)
	{
		if((str[i]>='0'&&str[i]<='5')||(str[i]=='.'))
		{}
		else
		{
			flag=0;
			break;
		}
	}
	return flag;
}
int main()
{
	int t,i1,j1,i2,j2,k,l,m,n,row,col,i,j;
	
	// matrix to store the Integer values entered by the user and the values computed as result of formula
	double spreadsheet[10][10]={0};  
	
	// The actual spreadsheet which stores the content to be displayed
	char sheet[10][10][20]={0};	
	
	// Flag matrix to check whether cell contains value entered by the user or the one computed by the formula
	int flag[10][10]={0};
	
	// Input value received from user
	char input[20];
	
	// Cell number received from the user
	char cellnum[4];									
	char *sub;
	// Initialization of the sheet matrix to contain default values
	for(i=0;i<=5;i++)	
		for(j=0;j<=9;j++)
			{
				if(i==0&&j!=0)
					sheet[i][j][0]='A'+j-1;
				else
				if(i!=0 && j==0)
				    sheet[i][j][0] = '0'+i;
				else
				if(i==0&&j==0)
				 sheet[i][j][0]='\0';
				 else
				 sheet[i][j][0]='_';
			}
	// Infinite loop to take input till user quits
	while(1)
	{
	 double sum=0,avg=0;
	 int maxm=INT_MIN,minm = INT_MAX,cnt =0;
	 printf("\nEnter the cell number :  ");
	 scanf("%s",cellnum);
	 
	 if(cellnum[0]>='A' && cellnum[0]<='Z')
	 col = cellnum[0]-'A'+1;
	 else
	 
	 // Extracting the row and column number from cell number
	 col = cellnum[0] - 'a'+1;	
	 row = cellnum[1] - '1'+1;
	 if(row>9 || row<0 || col>9 || col<0)
	 {
	 	printf("\n Invalid cell number \n");
	 	continue;
	 }
	 printf("\nEnter the value to be inserted  :  ");		
	 scanf("%s",input);
	 
	 // checking if user entered formuula : AVERAGE( , )
	 if(strstr(input,"AVERAGE")!= NULL )
	 {
	 sub = strstr(input,"(");
	 if(sub ==NULL)
	 printf("Wrong input");
	  else
	  {
 		if(*(sub+1) >= 'A' && *(sub+1) <= 'Z')
 		j1= *(sub+1)-'A'+1;
 		else
 		j1= *(sub+1) - 'a'+1;
 		
 		i1 = *(sub+2)-'1'+1;
 		
 		sub=sub+4;
 		
 		if(*sub >= 'A'&& *sub <='Z')
 		j2= *sub - 'A'+1;
 		else
 		j2= *sub - 'a'+1;
 		
 		i2 = *(sub+1)-'1'+1;
 		if(i2 == i1)
 		{
 		 for(j=j1;j<=j2;j++)
 		 {
 		 	if(flag[i1][j] == 1)
 		 	{
 		 		avg+=spreadsheet[i1][j];
 		 		cnt++;
 		 	}
 
 		 }
 
 		}
 		if(j2 == j1)
 		{
 			for(i=i1;i<=i2;i++)
 		 {
 		 	if(flag[i][j1] == 1)
 		 	{
 		 		avg+=spreadsheet[i][j1];
 		 		cnt++;
 		 	}
 
 		 }
 		}
 	  spreadsheet[row][col] = avg/cnt;
 	  //strcpy(sheet[row][col],ftoa(spreadsheet[row][col]));
	  sprintf(sheet[row][col],"%.2f",spreadsheet[row][col]);
	  // Inserting the result into the cell
	  if(strlen(sheet[row][col])>6)
	  		{
	  		sheet[row][col][6]='.';
 	    	sheet[row][col][7]='.';
 	    	sheet[row][col][8]='\0';
	  		}
	  
	  }
 
	 }
	 else
	 // Checking if the user entered formula  : SUM( , )
	 if(strstr(input,"SUM") != NULL)						
	 {
 
	 	sub = strstr(input,"(");
	 if(sub ==NULL)
	 printf("Wrong input");
	  else
	  {
 		if(*(sub+1) >= 'A' && *(sub+1) <= 'Z')
 		j1= *(sub+1)-'A'+1;
 		else
 		j1= *(sub+1) - 'a'+1;
 		
 		i1 = *(sub+2)-'1'+1;
 		
 		sub=sub+4;
 		
 		if(*sub >= 'A'&& *sub <='Z')
 		j2= *sub - 'A'+1;
 		else
 		j2= *sub - 'a'+1;
 		
 		i2 = *(sub+1)-'1'+1;
 		if(i2 == i1)
 		{
 		 for(j=j1;j<=j2;j++)
 		 {
 		 	if(flag[i1][j] == 1)
 		 	{
 		 		sum+=spreadsheet[i1][j];
 		 		cnt++;
 		 	}
 
 		 }
 
 		}
 		if(j2 == j1)
 		{
 			for(i=i1;i<=i2;i++)
 		 {
 		 	if(flag[i][j1] == 1)
 		 	{
 		 		sum+=spreadsheet[i][j1];
 		 		cnt++;
 		 	}
 
 		 }
 		}
 	  spreadsheet[row][col] = sum;
	  //strcpy(sheet[row][col],ftoa(sum));
	  sprintf(sheet[row][col],"%.2f",spreadsheet[row][col]);         
	  // inserting result into the cell
	  if(strlen(sheet[row][col])>6)
	  		{
	  		sheet[row][col][6]='.';
 	    	sheet[row][col][7]='.';
 	    	sheet[row][col][8]='\0';
	  		}
 
	  }
 
	 }
	 else
	 if(strstr(input,"RANGE") != NULL)						
	 // Checking if the user enterd formula : RANGE( , )
	 {
	 sub = strstr(input,"(");
	 if(sub ==NULL)
	 printf("Wrong input");
	  else
	  {
 		if(*(sub+1) >= 'A' && *(sub+1) <= 'Z')
 		j1= *(sub+1)-'A'+1;
 		else
 		j1= *(sub+1) - 'a'+1;
 		
 		i1 = *(sub+2)-'1'+1;
 		
 		sub=sub+4;
 		
 		if(*sub >= 'A'&& *sub <='Z')
 		j2= *sub - 'A'+1;
 		else
 		j2= *sub - 'a'+1;
 		
 		i2 = *(sub+1)-'1'+1;
 
 
 		if(i1 == i2)
 		{
 			for(j=j1;j<=j2;j++)
 			{
 				if(flag[i1][j] == 1 && maxm<spreadsheet[i1][j])
 					maxm = spreadsheet[i1][j];
 				if(flag[i1][j] == 1 && minm > spreadsheet[i1][j])
 					minm = spreadsheet[i1][j];
 			}
 		}
 		if(j1 == j2)
 		{
 			for(i=i1;i<=i2;i++)
 			{
 				if(flag[i][j1] == 1 && maxm < spreadsheet[i][j1])
 					maxm = spreadsheet[i][j1];
 				if(flag[i][j1] == 1 && minm > spreadsheet[i][j1])
 					minm = spreadsheet[i][j1];
 
 			}
 
 		}
 		spreadsheet[row][col] = maxm-minm;
 		//strcpy(sheet[row][col],ftoa(spreadsheet[row][col]));
 		sprintf(sheet[row][col],"%.2f",spreadsheet[row][col]);		
 		// Inserting the result into the cell
 	    if(strlen(sheet[row][col])>6)
	  		{
	  		sheet[row][col][6]='.';
 	    	sheet[row][col][7]='.';
 	    	sheet[row][col][8]='\0';
	  		}
	 }
	}
	 else if(isNumber(input))
	 // Checking if the value entered by the user is a number
	 {
	  spreadsheet[row][col] = atoi(input);
	  flag[row][col] = 1;
	  strcpy(sheet[row][col],input);
	  if(strlen(sheet[row][col])>6)
	  		{
	  		sheet[row][col][6]='.';
 	    	sheet[row][col][7]='.';
 	    	sheet[row][col][8]='\0';
	  		}
	 }
	 else
	 {
	 	strcpy(sheet[row][col],input);		
	 	// If value entered is text ,  simply insert the text into the cell
	 	if(strlen(sheet[row][col])>6)
	  		{
	  		sheet[row][col][6]='.';
 	    	sheet[row][col][7]='.';
 	    	sheet[row][col][8]='\0';
	  		}
	 }
	 
	 for(i=0;i<=5;i++)
	 {
	 	for(j=0;j<=5;j++)
	 		printf("%8s   ",sheet[i][j]);
	 	printf("\n");
	 }
 
	 printf("\n\n Pervious input  :  Cell Number : %s , Value : %s\n\n",cellnum,input);
	}
	return 0;
}