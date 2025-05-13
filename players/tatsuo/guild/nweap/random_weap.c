#define NIN_WEAP_PATH "/players/tatsuo/guild/nweap/"

// this list must be sorted by level !!!
#define NIN_WEAP \
                ({ "nstick","yari","nagimaki","bisento","naginata","gama",\
                   "kama","nunchaku","sa-tja-koen","shogi","sai" })

int *weapons;                      // format ({ lvl1,lvl2,noOfHndsNeeded, ...});
int no_of_weaps;

void reset( int tick )
{
   int    i;

   if ( tick ) return;

   no_of_weaps = sizeof( NIN_WEAP );
   weapons = ({});

   for ( i = 0; i < no_of_weaps; i++ ) {
      weapons+=({(NIN_WEAP_PATH+NIN_WEAP[i])->query_needed_lvl_fst()});
      weapons+=({(NIN_WEAP_PATH+NIN_WEAP[i])->query_needed_lvl_sec()});
      if ( (NIN_WEAP_PATH+NIN_WEAP[i])->query_two_handed() ) weapons+=({2});
      else weapons += ({1});
   }
}

int equip( object who, int level, int hands )
{
   int    max_idx, rnd, dec;
   object weap;

   max_idx = no_of_weaps-1;
   while ( max_idx >= 0 && weapons[max_idx*3] > level ) max_idx--;
   if ( max_idx < 0 ) return( 0 );
   if ( weapons[max_idx*3+2] > hands ) return( 0 );

   dec = 1;
   while( hands > 0 ) {
      rnd = random( max_idx*10 ) / 10;
      hands -= weapons[rnd*3+2];
      if ( hands < 0 ) return( 1 );
      weap = clone_object(NIN_WEAP_PATH+NIN_WEAP[rnd]);
      transfer( weap, who );
      command( "wield "+weap->query_name(), who );
      if ( dec ) {
         while ( max_idx >= 0 && weapons[max_idx*3] > level ) max_idx--;
         if ( max_idx < 0 ) return( 1 );
         if ( weapons[max_idx*3+2] > hands ) return( 1 );
      }
   } 

   return( 1 );
}
