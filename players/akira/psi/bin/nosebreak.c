
/*==========================================================================
       NOSEBREAK (monster) This ability is for those monsters that you
                           just can't seem to knockout. So you blind
                           them with there own blood and tears.
==========================================================================*/
#define COST 25
#define MIN_LEVEL 29


int main( string str ) {

   int tim;
   object ob, shad;

  if( !str ) {
    ob=this_player()->query_attack();
    if( ob ) str=ob->query_name();
    else {
      write("Break whos nose?\n");
      return 1;
    }
  } else ob=present( str, environment(this_player()) );

  if((!ob) || (!living(ob)) || (ob->query_immortal())) {
    write("You can't break "+ capitalize(str) +"'s nose!\n");
    return 1;
  }

  if(ob->query_npc())
  shad = clone_object("/players/akira/psi/shadows/blind_shad");
  shad -> start_shadow( ob, 20);
  write( "You shatter "+ ob->query_name() +"'s nose!\n");
  say(this_player()->query_name()+" shatters "+ob->query_name()+"'s nose.\n");
 tell_object(ob, this_player()->query_name()+" shatters your nose forceing\n"+
             "your own blood and tears to blind you!\n");
  return 1;
}
