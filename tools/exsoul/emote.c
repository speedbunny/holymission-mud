emo(str) {
  ghost();
  if (!str) return;
  say(cap_name+" "+str+"\n");
  write(cap_name+" "+str+"\n");
  return 1;
}
 
 
/*
emo(str) {
object list,player;
int i;
        ghost();
        if (!str) return 0;
        list=users();
        for (i=0; i<sizeof(list); i++) {
                player=list[i];
                if (player && living(player) && !player->query_npc() &&
                        present(player, environment(this_player()))) {
                        tell_object(player, cap_name+ " " +str+"\n");
                }
        }
        return 1;
}
*/
