object clone_object(string name) {
  if (this_object()->query_npc() &&
      (strstr(file_name(this_object()),"#") == -1) ) {
    log_file("BAD_CLONE_OBJECT",file_name(this_object())+" cloned "+name+"\n");
  }
  return efun::clone_object(name);
}
