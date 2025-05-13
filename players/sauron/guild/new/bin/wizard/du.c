#include "/players/sauron/secure/include/bin_functions.c"

int dump_dir(string dir,int silent);
status main(string str);

int dump_dir(string dir,int silent) {
  string *f;
  int fsize,dirsize,i;

  f=get_dir(dir+".");
  for(i=0;i<sizeof(f);i++) {
    f[i]=dir+f[i];
    fsize=0;
    if(!TP->valid_read(f[i]+"/"))
      printf("   0 K: %-60s\n",f[i]+"/ (no read access)");
    else if((fsize=file_size(f[i]))==-2) 
      fsize=dump_dir(f[i]+"/",silent);
    dirsize+=fsize;
  }
  if(!silent)
    printf("%4d K: %-60s\n",dirsize/1024,dir);
  return dirsize;
}

status main(string str) {
  string dir;
  int dsize,silent;

  if(str && sscanf(str,"%s %d",dir,silent)!=2)
    dir=str;
  dir=expand_filename(dir);
  if(!dir)
    return 1;
  if(file_size(dir)!=-2) {
    printf("No Such directory: '%s'.\n",dir);
    return 1;
  }
  dsize=dump_dir(dir+"/",silent)/1024;
  printf("\nTotal usage for '%s' = %d Kb.\n",dir,dsize);
  return 1;
}
