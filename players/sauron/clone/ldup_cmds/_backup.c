inherit "/players/sauron/clone/ldup_cmds/extras";

#pragma strict_types
#pragma save_types

int _backup(string str) {
  string *backupfiles,*exstr;
  string bytes,backupdir,endstr,path,str2,altstr;
  int start,block,size,backupnum,a,d,i,n;
  backupdir="/players/"+this_player()->query_real_name()+"/backup";
  if(file_size(backupdir)!=-2)
    mkdir(backupdir);
  if(!str)
    return (int)"/players/sauron/clone/ldup_cmds/_ls"->_ls(backupdir);
  str=lib_fn_expand(str);
  exstr=explode(str,"/");
  altstr=exstr[sizeof(exstr)-1];
  exstr[sizeof(exstr)-1]="";
  path=implode(exstr,"/");
  backupfiles=get_dir(str);
  if(!sizeof(backupfiles) || file_size(path+altstr)==-2) {
    str=str+"/.";
    path=path+altstr+"/";
    backupfiles=get_dir(str);
  }
  if(!sizeof(backupfiles)) {
    str=implode(exstr,"/")+altstr;
    printf("*File: %s does not exist.\n",str);
    return 1;
  }
  for(i=0;i<sizeof(backupfiles);i++) {
    if(backupfiles[i]=="." || backupfiles[i]=="..") {
      a++;
      continue;
    }
    else if(file_size(path+backupfiles[i])==-2) {
      d=1;
      continue;
    }
    /* Must copy in blocks <= 50k */
    /* Note: 3rd arg in read_bytes is _not_ end byte, as specified in docs */
    start=0;
    block=50000;
    size=file_size(path+backupfiles[i]);
    backupnum=1;
    while(file_size(backupdir+"/"+backupfiles[i]+";"+to_string(backupnum))!=-1)
      backupnum++;
    while(start<size) {
      bytes=read_bytes(path+backupfiles[i],start,block);
      if(!bytes) {
        printf("*File: Error reading file %s at byte %s\n",
          path+backupfiles[i],start);
      }
      else if(!write_file(backupdir+"/"+backupfiles[i]+";"+backupnum,bytes)) {
        printf("*File: Error writing to %s/%s;%d\n",
          backupdir,backupfiles[i],backupnum);
      }
      start+=block;
    }
    printf("*File: %s backed up as\n       %s/%s;%d.\n",
      path+backupfiles[i],backupdir,backupfiles[i],backupnum);
    if(backupnum>=2) printf("*File: You now have %d backups of this file. Is"
                           +" that what you want?\n",backupnum);
    if(backupnum>=10) printf("*File: Are you sure you need %d backups of this"
                            +" file?\n",backupnum);
    n++;
  }
  if(n) printf("*Total: %3d out of %3d files "
              +"backed up.\n",n,(sizeof(backupfiles)-a));
  if(d) write("*File: Sorry but you can't backup directories.\n");
  return 1;
}
