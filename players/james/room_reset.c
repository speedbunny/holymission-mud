mixed *clone_list;

reset() {
int i,j,k,l,n,id,index;
object ob, *all;
mixed *monsters;

if (clone_list) {
  monsters = ({ });
  all = all_inventory(this_object());
  if (!all) all= ({ });
  for(i=0; i<sizeof(clone_list); i += 5) {
    if ((id=clone_list[i]) == 0) continue; 
    if (id > 0) { 
      if(!(index=member_array(id,monsters)+1)) {
        monsters += ({ id, ({ }) });
        index = sizeof(monsters)-1;
      }
      n = clone_list[i+1];
      for(j=0; j<sizeof(all); j++)
        if ((int) call_other(all[j], "id", clone_list[i+2])) n -= 1;
      for(j=0; j<n; j++) {
        ob = clone_object(clone_list[i+3]);
        for(k=0; k<sizeof(clone_list[i+4]); k+=2)
          call_other(ob, clone_list[i+4][k], clone_list[i+4][k+1]);
        monsters[index] += ({ ob });
        move_object(ob, this_object());
        all += ({ ob });
      }
    } else { //Clone items for any monsters we've created
      if(index=member_array(-id,monsters)+1)
        for(l=0; l<sizeof(monsters[index]); l++)
          for(j=0; j<clone_list[i+1]; j++) {
            ob=clone_object(clone_list[i+3]);
            for(k=0; k<sizeof(clone_list[i+4]); k+=2)
              call_other(ob, clone_list[i+4][k], clone_list[i+4][k+1]);
            move_object(ob, monsters[index][l]);
          }
    }
  }
}
}
