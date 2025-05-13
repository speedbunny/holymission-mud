inherit "/players/sauron/clone/ldup_cmds/extras";

#pragma strict_types
#pragma save_types

void lib_failed();
string lib_fn_expand(string f1);
int lib_multi_copy_file(string f1,string f2,int copy);
int lib_file_exists(string f1);
mixed *del_array(mixed *array,int index);

int lib_multi_copy_file(string f1,string f2,int copy) {
  string all,tmp1,tmp2,fname,path1,path2;
  string *tmp,*files;
  int i,j,s1,s2,start,block;
  /* get filename without path in 'fname' */
  fname=f1;
  while(sscanf(fname,"%s/%s",tmp1,tmp2)==2)
    fname=tmp2;
  f1=lib_fn_expand(f1);
  if(!f1)
    return 0;
  f2=lib_fn_expand(f2);
  if(!f2)
    return 0;
  /* get sourcepath and destinationpath */
  s1=file_size(f1);
  if(s1!=-2) {
    tmp=explode(f1,"/");
    tmp=del_array(tmp,sizeof(tmp)-1);
    path1=implode(tmp,"/");
  }
  else path1=f1;
  if(path1[-1..-1]!="/") path1+="/";
  s2=file_size(f2);
  if(s2!=-2) {
    tmp=explode(f2,"/");
    tmp=del_array(tmp,sizeof(tmp)-1);
    path2=implode(tmp,"/");
  }
  else
    path2=f2;
  if(path2[-1..-1]!="/") path2+="/";
  /* now see if source is mutiple, single or empty (j) */
  if(s1!=-2) files=get_dir(f1);
  else files=get_dir(f1+"/.");
  if(!(j=sizeof(files))) {
    write("*File: Sorry, I cannot find "+f1+".\n");
    return 0;
  }
  /* if source is mutiple destination has to be a dir */
  if((j>1)&&(s2!=-2)) {
    write("*File: If you use wildcards, destination has to be a dir!\n");
    return 0;
  }
  if(j>1) {
    /* use multi-copy to another dir */
    int multi_ok;
    multi_ok=1;
    write("*File: Source is multifile, destination is a dir. Starting now.\n");
    for(i=0;i<j;i++) {
      string file;
      if(files[i]!="." && files[i]!="..") {
        s1=file_size(path1+files[i]);
        if(s1==-2)
          write("*File: Skipping "+path2+files[i]+" - its a dir.\n");
        else {
          s2=file_size(path2+files[i]);
          if(s2>=0 && !rm(path2+files[i]))
            printf("*File: Could not remove file %s\n",path2+files[i]);
          else {
            start=0;
            block=50000;
            while(start<s1) {
              if(!start) printf("*File: Reading %s\n",path1+files[i]);
              file=read_bytes(path1+files[i],start,block);
              if(!file)
                printf("*File: Error reading file %s at byte %s\n",
                  path1+files[i],start);
              if(!start) printf("*File: Writing %s\n",path2+files[i]);
              if(!write_file(path2+files[i],file))
                printf("*File: Error writing to %s\n",path2+files[i]);
              start+=block;
            }
            if(!copy && !rm(path1+files[i]))
              printf("*File: Could not remove original file (%s)\n",
                path1+files[i]);
            if(!lib_file_exists(path2+files[i]))
              multi_ok=0;
          }
        }
      }
    }
    return multi_ok;
  } /* end multi-copy */
  /* use single-copy to another dir or to a copy in same dir */
  s2=file_size(f2);
  if(s2==-2) {
    f2=f2+"/"+fname;
    write("*File: Destination is a dir. Keeping the filename the same.\n");
  }
  if(s2>=0 && !rm(f2)) {
    printf("*File: Could not remove file %s\n",f2);
    return 0;
  }
  start=0;
  block=50000;
  while(start<s1) {
    if(!start) printf("*File: Reading %s\n",f1);
    file=read_bytes(f1,start,block);
    if(!file) printf("*File: Error reading file %s at byte %s\n",f1,start);
    if(!start) printf("*File: Writing %s\n",f2);
    if(!write_file(f2,file)) printf("*File: Error writing to %s\n",f2);
    start+=block;
  }
  if(!copy && !rm(f1))
    printf("*File: Could not remove original file (%s)\n",f1);
  if(!lib_file_exists(f2)) return 0;
  /* end single-copy */
  return 1;
}

int cpmv(string str,int copy) {
  int i,s1,s2;
  string f1,f2,tmp1,tmp2,fname;
  string *parm;
  if(!str) {
    printf("Syntax:- %s <file(s)> <file/dir>\n",query_verb());
    return 1;
  }
  parm=explode(str," ");
  if(sizeof(parm)!=2) {
    printf("Syntax:- %s <file(s)> <file/dir>\n",query_verb());
    return 1;
  }
  if(lib_multi_copy_file(parm[0],parm[1],copy))
    write("*File: Done.\n");
  else
    lib_failed();
  return 1;
}
