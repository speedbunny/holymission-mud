inherit "obj/treasure";

string h1;

#define TP (this_player())

void end_it(){
 write("You shimmer into your own body.\n");
 destruct(this_object());
}


reset( arg )
{
   if ( arg )
      return;
      
   name = "statuer";
}
	init( ) {
        ::init();
        call_out("end_it",30);
        add_action( "block", "", 1 );
}                 

block(arg) {
      if ( query_verb() == "who" || query_verb() == "help" || query_verb() == "say" || query_verb() == "ninja" ||
           query_verb()=="'" || query_verb() == "tell" || query_verb() == "look" || query_verb() == "l" ||
    	   query_verb() == "save" || query_verb() == "alias" || query_verb() == "rwhere") {
        return(0);
}
	else {
      	write("You can't do that.\n");
	write("You are statue of "+this_player()->query_name()+".\n");
       	return(1);
}}
