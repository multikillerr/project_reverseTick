#include<iostream>
#include<dirent.h>
//#include<algorithm>
#include<stdlib.h>
#include<unistd.h>
#include<vector>
#include<sys/types.h>
#include<string>
//Change into the project directory and crawl through all the sub-directories and files
std::vector<std::string> read_directory(const std::string& name, std::vector<std::string> &v){
  DIR* dirp=opendir(name.c_str());
  struct dirent * dp;
  while((dp=readdir(dirp))!=NULL){
    v.push_back(dp->d_name);
  }
  return v;

}
int main(int argc,char **argv){
  std::string name;
  std::vector<std::string> v;
  read_directory(argv[1],v);
  for(int i=0;i<v.size();i++){
    std::cout<<v[i]<<"\n";
  }
  return 0;

}
