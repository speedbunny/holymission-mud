inherit "players/sargon/obj/spliff";
reset(arg) { 
        ::reset(arg); 
        if (arg) return; 
        set_sort( "collie herb" ); 
        set_sortkey( "spliff_c"); 
       set_value(150);
      set_strength(400);
        set_draws( 7 ); 
} 
