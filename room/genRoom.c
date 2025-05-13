#pragma strict_types
#include <lw.h>
#include "/room/clean_up.c"

private mapping dest_dir;
private mapping items;
private string  short_desc;
private string  long_desc;
private mixed   property;
private string  no_obvious_msg;

#define ROOMINFO "room/roominfo"

void init()
{
   int   i;
   mixed *idx;

   i = m_sizeof( dest_dir );
   idx = m_indices( dest_dir );
   for ( --i; i >= 0; i-- )
      add_action( "move", idx[i] );
}

void reset(int arg) 
{ 
  int i,j,k,l,n,id,index;
  int h1, h2, h3;
  object ob, *all;
  mixed *monsters;

   dest_dir = ([]);

#if 0
  if (clone_list) 
  {
    monsters = ({ });
    all = all_inventory(this_object());
    
    if (!all) all= ({ });

   /* will only calculate sizeof 1 time Whisky */

    for( h1 = sizeof(clone_list), i=0; i < h1; i += 5) 
    {
      if ((id=clone_list[i]) == 0) continue; 
      if (id > 0) 
      { 
        if(!(index=member_array(id,monsters)+1)) 
	{
          monsters += ({ id, ({ }) });
          index = sizeof(monsters)-1;
        } /* endif */
        n = clone_list[i+1];
        for(h2 = sizeof(all),j=0; j < h2; j++)
          if ((int) call_other(all[j], "id", clone_list[i+2])) n -= 1;
        for(j=0; j<n; j++) 
  	{
           ob = clone_object(clone_list[i+3]);
           for( h3=sizeof(clone_list[i+4]), k=0; k < h3; k+=2)
             call_other(ob, clone_list[i+4][k], clone_list[i+4][k+1]);
           monsters[index] += ({ ob });
           move_object(ob, this_object());
           all += ({ ob });
        } /* endfor */
      } else 
      {   //Clone items for any monsters we've created,buit don't use that !
        if(index=member_array(-id,monsters)+1)
          for(h2 = sizeof(monsters[index]), l=0; l < h2; l++)
            for(j=0; j<clone_list[i+1]; j++) 
            {
              ob=clone_object(clone_list[i+3]);
              for(h3 = sizeof(clone_list[i+4]),k=0; k < h3; k+=2)
                call_other(ob, clone_list[i+4][k], clone_list[i+4][k+1]);
              move_object(ob, monsters[index][l]);
              if (ob->query_weapon())
                command(sprintf("wield %s",clone_list[i+2]),monsters[index][l]);
              if (ob->query_armour())
                command(sprintf("wear %s",clone_list[i+2]),monsters[index][l]);
            } /* endfor */
      }  /* endif */
    } /* endif */
  } /* endfor */
#endif
}

status id(string str) 
{
    return( items && items[str] );
}

void long(string str)  /* be careful called very often */
{
   int i;

   if ( !this_player() ) return;

   if ( !str && stringp(long_desc) )
   {
      writelw( process_string(long_desc) );
      if( !no_obvious_msg )
         no_obvious_msg=(string)ROOMINFO->get_long_exits(query_dest_dir());
      write(no_obvious_msg);
      return;
   }

   if ( mappingp(items) && items[str] )
      writelw( process_string(items[str]) + "\n" );
}

int add_exit( string verb, string arg, string dest, int map, int hidden )
{
   dest_dir[verb] = ({arg,dest,map,hidden});
}

mixed query_property(string str) 
{
  int i;
  if(!str) return property;
  if(pointerp(property)) return member_array(str, property) != -1;
  return str==property;
}

status query_no_teleport() 
{
  return (status)query_property("no_teleport");
}

status move( string arg ) 
{
   string verb;
   mixed  parg;

   verb = query_verb();
   if ( !dest_dir[verb] )
      return( 0 );
   parg = dest_dir[verb][0];
   if ( parg ) {
      if ( (stringp(parg) && arg == parg) 
           || (pointerp(parg) && member_arry(arg,parg)) )
      {
         (void)this_player()->move_player("argl",dest_dir[verb][1]);
         return( 1 );
      }
      return( 0 );
   }
   (void)this_player()->move_player( verb, dest_dir[verb][1] );

   return( 1 );
}

string short() 
{ 
   if (this_player()->test_dark())
       return "It's pitch dark";
   else
       return short_desc;
}

mapping query_dest_dir() 
{
   return( dest_dir );
}

mapping query_hidden_dir() 
{
   return( dest_dir );
}

mapping query_items()
{
   return( items );
}

int test_darkness()
{
   if(this_player() && this_player()->infravision()) return 1;
   return set_light(0);
}

int test_dark()
{
   return( set_light(0) );
}

int lcatch_tell( string act, string msg, object who )
{
   if ( who && living(who) )
      tell_object( this_object(),
                   capitalize((string)who->query_real_name())+" "+act+" "+msg );
   return( 1 );
}
