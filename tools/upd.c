/*-------------------------------------------------------------------------*/
/* FILE : upd.c                                                            */
/*                                                                         */
/* Description : This is an include file to be used to add actions that    */
/*               call these two functions. Mostly, should only be used in  */
/*               tools or sys files. Ask as arch if you want to include it */
/*               elsewhere.                                                */
/*               DO NOT COPY THIS FILE!                                    */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Mar 15 1997  Kryll        Cleaned up this file. Added decent comments.
 
*/

// This function updates an entire current directory.
int _upd() {
  string path;
  string *files;
  object master;
  int i, sz;

  path = "/"+this_player()->query_path()+"/";
  files = get_dir(path+".");

  for(sz=sizeof(files), i=0; i<sz; i++) {
    if(master = find_object(path+files[i])) {
      write(files[i] + "\n");
      destruct(master);
    }
  }
  write("Ok, "+path+" updated.\n");
  return 1;
}

// This function loads an entire current directory.        
int _ld() {
  string path;
  string *files;
  int i, sz;

  path = "/"+this_player()->query_path()+"/";
  files = get_dir(path+".");

  for(sz=sizeof(files), i=0; i<sz; i++) {
    if(!catch(call_other(path+files[i], "???"))) {
      write(files[i] + "\n");
    }
  }
  write("Ok, "+path+" loaded.\n");
  return 1;
}
