#include "/players/sauron/secure/include/bin_functions.c"

int main(string str) {
  string exp,dir,pathname,*tmp,*files,*lines;
  int i,j,k;
  object tp;

  NF("Syntax: 'grep <expression> <files>'.\n");

  if(!str)
    return 0;

  tmp=get_strings(str);
  if(sizeof(tmp)!=2)
    return 0;

  exp=tmp[0];
  dir=tmp[1];

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

  files=get_dir(dir);

  if(!(j=sizeof(files))) {
    NF("*File: No such file or directory: "+dir+"\n");
    return 0;
  }
  for(i=0;i<j;i++) {
    string file;
    if(files[i]!="." && files[i]!="..") {
      file=read_file(pathname+files[i]);
      if(file && sizeof(explode(file,exp))>1) {
        printf("\nFound expression '%s' in '%s%s'\n",exp,pathname,files[i]);
        lines=explode(file,"\n");
        for(k=0;k<sizeof(lines);k++)
          if(sizeof(explode(lines[k],exp))>1)
	    printf("%4d: %s\n",k+1,lines[k]);
      }
    }
  }
  write("\nDone.\n");
  return 1;
}
