#include "/players/sauron/secure/include/bin_functions.c"

int main(string str) {
  string exp,newexp,dir,pathname,*tmp,*files,*lines;
  int i,j;

  NF("Syntax: 'frep <old-string> <new-string> <files>'.\n");

  if(!str)
    return 0;

  tmp=get_strings(str);
  if(sizeof(tmp)!=3)
    return 0;

  exp=tmp[0];
  newexp=tmp[1];
  dir=tmp[2];

  dir=expand_filename(dir);

  if(file_size(dir)==-2)
    pathname=(dir+="/");
  else {
    tmp=explode(dir,"/");
    tmp[<1]="";
    pathname=implode(tmp,"/");
    if(pathname[<1..<1]!="/")
      pathname+="/";
  }

  if(!TP->valid_read(dir)) {
    NF(sprintf("Unable to read source code for '%s'.\n",dir));
    return 0;
  }
  else if(!TP->valid_write(pathname)) {
    NF(sprintf("Unable to write result to '%s'.\n",pathname));
    return 0;
  }

  files=get_dir(dir);

  if(!(j=sizeof(files))) {
    NF("*File: No such file or directory: "+dir+"\n");
    return 1;
  }

  printf("Will change '%s' to '%s' in '%s'.\n",exp,newexp,dir);
  for(i=0;i<j;i++) {
    string file;
    if(files[i]!="." && files[i]!= ".." && 
      file=read_file(pathname+files[i])) {
      lines=explode(file,exp);
      if(file && sizeof(lines)>1) {
        printf("Replacing '%s' in '%s%s'.\n",exp,pathname,files[i]);
        file=implode(lines,newexp);
        if(rename(pathname+files[i],pathname+files[i]+".bak"))
          write("Non-fatal error.\n");
        write_file(pathname+files[i],file);
      }
    }
  }
  write("Done.\n");
  return 1;
}
