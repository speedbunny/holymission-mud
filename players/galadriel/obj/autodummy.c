/* 12-SEP-93 Galadriel: 
This is a dummy object that you can use for removing autoload objects that no
longer exist. It prevents a 'Could not load desc for ..' error and also saves
the playername and the time, so you know when its safe to rm the dummy object
Just copy this file to the filename where the autoloader used to be. G for HM
*/

void reset(int arg) {
  string *tmp,logname;

  /* try to find the wiz name for the logfile name */
  tmp=explode(file_name(this_object()),"/");
  switch(tmp[0]) {
    case "players" : logname=tmp[1]+".rmautoload"; break;
    default        : logname="galadriel.rmautoloadx"; break;
  }
  log_file(logname,"rmed "+file_name(this_object())+
                   "\nfrom "+this_player()->query_real_name()+
                   " at "+ctime(time())+"\n");
  destruct(this_object());
}
