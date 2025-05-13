int filter_live(object ob, string mon_name){
  int i, j, sz;
  object *inv;

  if (!first_inventory(ob)) return 0;

     inv = all_inventory(ob);
     sz =0;
     j=sizeof(inv);
     
     for (i=0; i < j; i++)
         if (living(inv[i])&&((inv[i]->short())==mon_name)) sz++;
     return sz;
}

int filter_monster(object ob){
  int i, j, sz;
  object *inv;
  
  if (!first_inventory(ob)) return 0;
  
  inv = all_inventory(ob);
  sz =0;
  j=sizeof(inv);
  
  for (i=0; i < j; i++)
       if (living(inv[i])&&((inv[i]->id("monster")))) sz++;
  return sz;
}

int clone_x_of_y(int number, string mon_path){
  int counter;

  for(counter=0;counter<number;counter++)
    move_object(clone_object(mon_path),this_object());
  return 1;
}
