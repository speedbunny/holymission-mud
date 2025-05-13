inherit "obj/treasure";

string *DIRS;
int movies;

#define MaxMovies this_player()->query_chr()*3
#define TP this_player()

object seek;


void set_seek(object who){
 seek=clone_object("players/goldsun/religion/mist");
 move_object(seek,environment(who));
 seek->set_mist_of_whom(who);
}


reset( arg )
{
   if ( arg )
      return;
   movies=MaxMovies;
   DIRS=({"north","south","west","east","up","down","enter","out",
	  "northwest","northeast","southwest","southeast"});
   name = "meditator";
}


init( )
{
   ::init();
   
   add_action( "stop_meditate",  "return" );
   add_action( "stop_meditate","re");
   add_action( "block", "", 1 );
}


block( arg )
{
 if  (query_verb()=="look"){
     seek->show_this();
     return 1;
 }
 if  (member_array(query_verb(),DIRS) != -1){
   if (movies==0){
     this_player()->remove_spell_points(this_player()->query_sp());
     stop_meditate();
     return 1;
   }
   seek->mover(query_verb());
   movies--;
   return 1;
 }
 if ( query_verb() == "return" || query_verb() == "re" || query_verb() == "who"
      || query_verb() == "save" 
    ){
      return 0;
  }
      write( "You can't do that in your immaterial state. <to return back type"+
       " \"return\">\n" );
      return( 1 );
 }


stop_meditate(){
object shd;

 if (TP->relig_shad()) TP->query_relig_shad()->end_shadow();
 write("You turn back to your material state.\n");
 if (seek){
    write("Undefined force smashes you.\n");
    destruct(seek);
 }
 destruct(this_object());
 return 1;
}
