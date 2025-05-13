inherit "obj/treasure";
  
reset(arg) {
    
  if (arg) return;

  set_name( "parchment" ); 
  set_alt_name( "unreadable_ninja_parch" );
  set_short("A tattered parchment");
  set_long("A tattered parchment, nearly unreadable.\n");
  set_read("Strange ancient nihonese runes cover this paper, and you cannot\n"+
           "understand them at all!\n"+
           "Maybe show it to somebody who can decipher it.\n" );
}
