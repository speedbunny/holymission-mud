inherit "/players/sauron/clone/ldup_cmds/extras";

#pragma strict_types
#pragma save_types

int _ls(string path) {
  string file,tmp,d,ret,own,grp,perm,*arr;
  int fsize,i,j,num_dirs,num_files,date,fdate;
  mixed *f;

  if(path && sscanf(path,"-l %s",tmp)==1) {
    date=1;
    path=tmp;
  }
  else if(path=="-l") {
    date=1;
    path=(string)0;
  }

  path=lib_fn_expand(path);
  if(!path)
    return 1;

  else if(!this_player()->valid_read(path)){
    printf("%s: Access denied!\n",path);
    return 1;
  }

  fsize=file_size(path);
  switch(fsize) {
    case -2:
      if(path[<1..<1]!="/")
        path+="/";
      arr=get_dir(path+".");
      f=get_dir(path+".",-1);
      ret=sprintf("File list for '%s':\n\n",path);
      break;
    case -1:
      if(member(path,'?')==-1 && member(path,'*')==-1) {
        printf("%s: No such file or directory.\n",path);
        return 1;
      }
      else {
        arr=get_dir(path);
        f=get_dir(path,-1);
      }
      if(!sizeof(f)) {
        printf("%s: No match.\n",path);
        return 1;
      }
      else {
        ret=sprintf("File list for '%s':\n\n",path);
        path=implode(explode(path,"/")[0..<2],"/")+"/";
      }
      break;
    default:
      arr=get_dir(path);
      f=get_dir(path,-1);
      ret=sprintf("File list for '%s':\n\n",path);
      break;
  }

  fsize=0;
  num_dirs=0;
  num_files=0;
  if(date) {
    for(i=0;i<sizeof(arr);i++) {
      j=member_array(arr[i],f);
      fsize=f[j+1];
      fdate=f[j+2];
      if(time()-fdate>15724800) // half a year
        d=ctime(fdate)[4..10]+ctime(fdate)[<5..<1];
      else
        d=ctime(fdate)[4..15];
      if(sscanf(path+arr[i],"/players/%s/%s",own,tmp)==2) {
        grp="users";
        perm="-rw----";
        if(own==(string)this_player()->query_real_name())
          perm[4..4]="r";
        else {
          if(this_player()->valid_read(path+arr[i])) {
            perm[4..4]="r";
            if(this_player()->valid_write(path+arr[i]) && own != "sauron")
              perm[5..5]="w";
          }
        }
        perm+=perm[<3..<1];
      }
      else if(sscanf(path+arr[i],"/players/%s",own)==1) {
        grp="backbone";
        perm="-rw----";
        if(own==(string)this_player()->query_real_name())
          perm[4..4]="r";
        else {
          if(this_player()->valid_read(path+arr[i])) {
            perm[4..4]="r";
            if(this_player()->valid_write(path+arr[i]) && own != "sauron")
              perm[5..5]="w";
          }
        }
        perm+=perm[<3..<1];
      }
      else {
        own="backbone";
        grp="backbone";
        perm="-rw----";
        if(this_player()->valid_read(path+arr[i])) {
          perm[4..4]="r";
          if(this_player()->valid_write(path+arr[i]))
            perm[5..5]="w";
        }
        perm+=perm[<3..<1];
      }
      if(fsize!=-2) {
        if(!fsize)
          fsize=1;
        file=arr[i];
        if(find_object(path+arr[i]))
          perm[0..0]="*";
        ret=sprintf("%s%10s   1 %-11s %-8s %8d %s %s\n",
                    ret,perm,own,grp,fsize,d,file);
        num_files++;
      }
      else {
        file=arr[i]+"/";
        perm[0..0]="d";
        perm[3..3]="x";
        if(perm[4..4]=="r")
          perm[6..6]="x";
        if(perm[7..7]=="r")
          perm[9..9]="x";
        ret=sprintf("%s%10s   1 %-11s %-8s %8d %s %s\n",
                    ret,perm,own,grp,1024,d,file);
        num_dirs++;
      }
    }
  }
  else {
    for(i=0;i<sizeof(arr);i+=3) {
      j=member_array(arr[i],f);
      fsize=f[j+1];
      if(fsize==-2) {
        file=arr[i]+"/";
        ret=sprintf("%s%4s   %-19s",
                      ret,
                      this_player()->valid_read(path+arr[i])?"+":"-",
                      file);
        num_dirs++;
      }
      else {
        if(!fsize)
          fsize=1;
        file=arr[i];
        ret=sprintf("%s%4d %s %-19s",ret,fsize/1024+1,
                   (find_object(path+arr[i])?"*":" "),file);
        num_files++;
      }
      if((i+1)<sizeof(arr)) {
        j=member_array(arr[i+1],f);
        fsize=f[j+1];
        if(fsize==-2) {
          file=arr[i+1]+"/";
          ret=sprintf("%s%4s   %-19s",
                      ret,
                      this_player()->valid_read(path+arr[i+1])?"+":"-",
                      file);
          num_dirs++;
        }
        else {
          if(!fsize)
            fsize=1;
          file=arr[i+1];
          ret=sprintf("%s%4d %s %-19s",ret,fsize/1024+1,
                     (find_object(path+arr[i+1])?"*":" "),file);
          num_files++;
        }
      }
      if((i+2)<sizeof(arr)) {
        j=member_array(arr[i+2],f);
        fsize=f[j+1];
        if(fsize==-2) {
          file=arr[i+2]+"/";
          ret=sprintf("%s%4s   %-19s",
                      ret,
                      this_player()->valid_read(path+arr[i+2])?"+":"-",
                      file);
          num_dirs++;
        }
        else {
          if(!fsize)
            fsize=1;
          file=arr[i+2];
          ret=sprintf("%s%4d %s %-19s",ret,fsize/1024+1,
                     (find_object(path+arr[i+2])?"*":" "),file);
          num_files++;
        }
      }
      ret=sprintf("%s\n",ret);
    }
  }
  ret=sprintf("%s\nDirectories: %d  Files: %d  Total: %d\n",
              ret,num_dirs,num_files,num_dirs+num_files);
  this_player()->more_string(ret);
  return 1;
}
