#include "/players/sauron/secure/include/bin_functions.c"

int _rm(string str) {
  string *files,*exstr;
  string path,altstr;
  int i;
  if(!str) {
    write("Syntax: rm <file(s)>\n");
    return 1;
  }
  str=expand_filename(str);
  exstr=explode(str,"/");
  altstr=exstr[<1];
  exstr[<1]="";
  path=implode(exstr,"/");
  files=get_dir(str);
  if(!sizeof(files) && file_size(str)==-2) {
    path=str+"/";
    files=get_dir(str+"/.");
  }
  if(!sizeof(files)) {
    printf("*File: %s does not exist.\n",str);
    return 1;
  }

  for(i=0;i<sizeof(files);i++) {
    if(files[i]=="." || files[i]=="..") {
      continue;
    }
    else if(rm(path+files[i]))
      printf("*Removed: %s\n",path+files[i]);
    else if(rmdir(path+files[i]))
      printf("*Removed directory: %s\n",path+files[i]);
    else
      printf("*Cannot remove: %s\n",path+files[i]);
  }
  return 1;
}
