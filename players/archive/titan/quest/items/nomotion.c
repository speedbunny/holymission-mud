inherit "obj/treasure";

string h1;

#define TP (this_player())

reset( arg )
{
   if ( arg )
      return;
      
   name = "nomotion";
}
	init( ) {
        ::init();
        add_action( "block", "", 1 );
}                 

block(arg) {
      if ( query_verb() == "who" || query_verb() == "say" || query_verb() == "score" ||
           query_verb()=="'" || query_verb() == "tell" || query_verb() == "look" || query_verb() == "l" ||
    	   query_verb() == "save" || query_verb() == "destruct" || query_verb() == "des" ||
	   query_verb() == "alias" || query_verb() == "rwhere") {
        return(0);
}
	else {
      	write("You can't do that.\n");
       	return(1);
}}
