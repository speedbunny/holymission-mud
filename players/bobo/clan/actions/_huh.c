#define TP this_player

int _huh(string arg){
   say(TP()->query_name()+" says: Huh.\n");
   write("You say: Huh.\n");
   return 1;
}
