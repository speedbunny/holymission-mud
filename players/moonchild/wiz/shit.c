reset() {
  set_heart_beat(1);
}

heart_beat() {
  object *u;
  int i;
  u=filter_array(users(), "iastate", this_object());
  if(sizeof(u))
    for(i=0;i<sizeof(u);i++)
      destruct(u[i]);
}

iastate(ob) {
  return query_ip_number(ob) && query_ip_number(ob)[0..5]=="129.25";
}
