#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

#define COMMONCONFIG_FILEPATH "/DG/activeRelease/dat/CommonConfig.properties"

using namespace std;

int main()
{
   ifstream input(COMMONCONFIG_FILEPATH);
   string data="";
   string fqdn="";
   int redDeployType=0;
   if(input.is_open())
   {
      while(getline(input,data))
      {
         int pos=data.find("DEPLOYMENT_REDUNDANCY_TYPE",0,26);
         if(pos==0)
         {
            fqdn=data.substr(27);
            redDeployType=atoi(fqdn.c_str());
            printf("found correct one\n");
            printf("%d\n",redDeployType);
         }    
      }
      if(redDeployType==3)
      {
	  printf("Pri+Geo");
      }
      input.close();
   }
   else
      printf("CommonConfig.properties file not present\n");
   if(fqdn.empty())
      printf("empty ggfqdn\n");

}
