**  Elvira, intended to be a robot similar to Harry. She's currently in
**  development stages, and will eventually be converted to room code.
*/
inherit "obj/monster";
 
#define PUB   "/room/pub2"
#define SHOP  "/room/shop"
#define GUILD "/room/adv_guild"
 
/* What does query_gender() return? */
#define MALE   1
#define FEMALE 2
#define NEUTER 0
 
reset ( int arg )
{
    ::reset ( arg );
    if ( ! arg )
    {
        set_name ( "elvira" );
        set_level ( 5 );
        set_short ( "Elvira" );
        set_long ( "This is one bad lady.\n" );
    }
    set_up();
}
 
set_up()
{
    string *match, *type, *function;
 
function = allocate ( 8 );
    type = allocate ( 8 );
    match = allocate ( 8 );
 
    function[0] = "follow";
    type[0] =     "leaves";
    function[1] = "greet_gender";
    type[1] =     "arrives";
    function[2] = "react_feeling";
    type[2] = "kicks you";
    type[3] = "slaps you";
    type[4] = "smiles at you";
    function[5] = "react_feeling_other";
    type[5] = "kisses";
    type[6] = "gives";
    function[7] = "respond";
 
type[7] = "says";
 
    set_match ( this_object(), function, type, match );
}
 
follow ( string str )
{
    string who, dir;
    object player;
 
#define T(mess) tell_object(find_player("wolflord"),mess + "\n" )
    if ( sscanf ( str, "%s leaves %s.", who, dir ) != 2 )
        return;
    who = lower_case ( who );
    if ( player = find_player ( who ) )
    {
      if ( environment ( player ) != environment() )
        {
            command ( dir, this_object() );
            if ( environment ( player ) == environment() )
            {
                if ( player->query_gender() == MALE )
                    say ( "Elvira says: Why ya leavin', big fella?\n" );
                else if ( player->query_gender() == FEMALE )
                    say ( "Elvira says: Hey lady, wait up!\n" );
                else if ( player->query_gender() == NEUTER )
                    say ( "Elvira says: Hey " + capitalize ( who ) +
                          ", what are you, anyway?\n" );
            }
        }
    }
}
 
greet_gender ( string who )
{
    object player;
 
    if ( sscanf ( who, "%s arrives.", who ) == 1 )
    {
        player = find_player ( lower_case ( who ) );
        if ( player && present ( player, environment() ) )
        {
            if ( player->query_gender() == MALE )
            {
                say ( "Elvira winks suggestively at " + who + ".\n", player );
                tell_object ( player, "Elvira winks suggestively at you.\n" );
            }
            else if ( player->query_gender() == FEMALE )
            {
                say ( "Elvira whispers something to " + who + ".\n", player );
                tell_object ( player, "Elvira whispers to you: Aren't " +
                                      "there some gorgeous hunks here?\n" );
            }
            else if ( player->query_gender() == NEUTER )
            {
                say ( "Elvira smiles at " + who + ".\n", player );
                tell_object ( player, "Elvira smiles at you.\n" );
            }
        }
    }
}
 
react_feeling ( string str )
{
    string who, emote;
    object player;
 
    if ( sscanf ( str, "%s %s you.", who, emote ) == 2 )
    {
        player = find_player ( lower_case ( who ) );
        if ( present ( player, environment() ) )
        {
            if ( emote == "kicks" || emote == "slaps" )
            {
                say ( "Elvira slaps " + who + ".\n", player );
                tell_object ( player, "Elvira slaps you.\n" );
            }
            else if ( emote == "smiles at" )
            {
                say ( "Elvira kisses " + who + " on the cheek.\n", player );
                tell_object ( player, "Elvira kisses you on the cheek.\n" );
            }
        }
    }
}
 
react_feeling_other ( string str )
{
    string who,     to_whom;
    object player1, player2;
 
    if ( sscanf ( str, "%s kisses %s", who, to_whom ) == 2 ||
         sscanf ( str, "%s gives %s a deep and passionate kiss, it seems" +
                       " to take forever...", who, to_whom ) == 2 )
    {
        player1 = find_player ( lower_case ( who ) );
        player2 = find_player ( lower_case ( to_whom ) );
        if ( ! player1 || ! player2 )
            return;
        who = capitalize ( who );
        if ( present ( player1, environment() ) )
        {
            say ( "Elvira pats " + who + ".\n", player1 );
            tell_object ( player1, "Elvira pats you.\n" );
        }
    }
}
