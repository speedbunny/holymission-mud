void reset(int arg)
  {
  write(query_imp_port() +"\n");
  destruct(this_object());
  }
