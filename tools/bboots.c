// Board Boots, for easy access to most of the available boards.
// 310194: Editted by Mangla to eliminate the say for invis wizzes
//         and removed guild change for jedi guild.
// 310194: Added barbarian and vagabond guilds to list
// 130294: Removed guild change for monks and sorted guilds
// 131296: Saffrin: Removed all guilds not in use and fixed the paths of
//         the boards themselves.
// 190396: Airborne: Fixed output.
// 201096: Sauron: Rewritten to version 2.0.
// 261096: Sauron: Incorporated ffind into find.
//                 Incorporated find_castle into find.
//                 Moved find to /sys/bin/appr.
// 051197: Sauron: Updated code.
// 211197: Sauron: Added 'new boards only' option.

#include <sys_defs.h>

#define VERSION		"v2.0"
#define DOTS		" .........."

// Defines for accessing the data in the mappings.

#define NUM		0
#define ALIAS		1
#define SDESC		2
#define ROOM		3
#define BOARD		4

static string  sFilename;
static int     iNewOnly, iAutoCatchup;
static mapping mCommon, mGuild, mWiz;

int id(string sStr) {
    if(sStr == "new boards" || sStr == "nbds") {
        iNewOnly = 1;
        return 1;
    }
    else {
        iNewOnly = 0;
        return sStr == "bboots" || sStr == "boardboots" ||
               sStr == "board boots" || sStr == "boards";
    }
}

mapping queryCommon() {
    return mCommon;
}

mapping queryGuild() {
    return mGuild;
}

mapping queryWiz() {
    return mWiz;
}

int activate(string sStr) {
    if(!sStr || !id(sStr))
        return 0;
    else {
        move_object(TO, ENV());
        write("Bboots activated.\n");
        return 1;
    }
}

int autoCatchup() {
    iAutoCatchup = !iAutoCatchup;
    printf("You will now %s when you goto a board.\n",
           (iAutoCatchup ?
                "automatically catchup on unread notes" :
                "view the note listing"));
    return 1;
}

int sendBoots(string sWho) {
    int    iUpdated, iMyself, iTmp;
    object oBoots, oPlayer;

    if(!sWho)
        oPlayer = TP;
    else
        oPlayer = find_living(sWho);
    if(!oPlayer)
        return 0;
    if(!oPlayer->IMM && !oPlayer->TESTP) {
        write("Insufficient clearence to receive Board Boots.\n");
        return 1;
    }
    oBoots = present("bboots", oPlayer);
    iMyself = (oPlayer == TP);
    if(oBoots && sscanf(file_name(oBoots), sFilename[1..<1]+"#%d", iTmp))
        iUpdated = 1;
    else
        iUpdated = 0;

    move_object(clone_object(sFilename), oPlayer);
    if(iMyself) {
        write("You update your Bboots.\n");
        destruct(oBoots);
        return 1;
    }
    if(!iUpdated) {
        printf("You send some Bboots to %s.\n", CAP(sWho));
        tell_object(oPlayer, TP->CRNAME+" sent you some BBoots.\n");
    }
    else {
        printf("You send some new Bboots to %s.\n", CAP(sWho));
        tell_object(oPlayer, TP->CRNAME+" sent you some new Bboots.\n");
        destruct(oBoots);
    }
    return 1;
}

varargs mixed *queryNameList(string sStr) {
    string *saCo, *saGu, *saWi;

    saCo = m_indices(mCommon);
    saGu = m_indices(mGuild);
    saWi = m_indices(mWiz);

    if(!sStr || sStr == "")
        return ({saCo, saGu, saWi});
    else if(member_array(sStr, saCo) != -1)
        return ({sStr, 0});
    else if(member_array(sStr, saGu) != -1)
        return ({sStr, 1});
    else if(member_array(sStr, saWi) != -1)
        return ({sStr, 2});
    else
        return 0;
}

varargs mixed *queryNumList(string sStr) {
    string *saCo, *saGu, *saWi;
    int    i, iNum, *iaC, *iaG, *iaW;

    saCo = m_indices(mCommon);
    saGu = m_indices(mGuild);
    saWi = m_indices(mWiz);

    iaC = ({});
    for(i = 0; i < sizeof(saCo); i++)
        iaC += ({mCommon[saCo[i]][NUM]});

    iaG = ({});
    for(i = 0; i < sizeof(saGu); i++)
        iaG += ({mGuild[saGu[i]][NUM]});

    iaW = ({});
    for(i = 0; i < sizeof(saWi); i++)
        iaW += ({mWiz[saWi[i]][NUM]});

    if(!sStr || sStr == "")
        return ({iaC, iaG, iaW});
    else if(sscanf(sStr, "%d", iNum) != 1)
        return 0;
    else if((i = member_array(iNum, iaC)) != -1)
        return ({saCo[i], 0});
    else if((i=member_array(iNum, iaG)) != -1)
        return ({saGu[i], 1});
    else if((i=member_array(iNum, iaW)) != -1)
        return ({saWi[i], 2});
    else
        return 0;
}

varargs mixed *queryAliasList(string sStr) {
    string *saCo, *saGu, *saWi, *saC, *saG, *saW;
    int    i;

    saCo = m_indices(mCommon);
    saGu = m_indices(mGuild);
    saWi = m_indices(mWiz);

    saC = ({});
    for(i = 0; i < sizeof(saCo); i++)
        saC += ({mCommon[saCo[i]][ALIAS]});

    saG = ({});
    for(i = 0; i < sizeof(saGu); i++)
        saG += ({mGuild[saGu[i]][ALIAS]});

    saW = ({});
    for(i = 0; i < sizeof(saWi); i++)
        saW += ({mWiz[saWi[i]][ALIAS]});

    if(!sStr || sStr == "")
        return ({saC, saG, saW});
    else if((i = member_array(sStr, saC)) != -1)
        return ({saCo[i], 0});
    else if((i = member_array(sStr, saG)) != -1)
        return ({saGu[i], 1});
    else if((i = member_array(sStr, saW)) != -1)
        return ({saWi[i], 2});
    else
        return 0;
}

object findBoard(mapping mMap, string sTmp) {
    object oRoom, oBoard;

    if(mMap[sTmp][BOARD])
        return mMap[sTmp][BOARD];

    else {
        catch(mMap[sTmp][ROOM]->aLoadFun());
        oRoom = find_object(mMap[sTmp][ROOM]);
        if(oRoom)
            oBoard = present("board", oRoom);
        mMap[sTmp][BOARD] = oBoard;
        return oBoard;
    }
}

int gotoABoard(string sRoom, string sName, object oBoard) {
    say(TP->TNAME+" takes a big step away to the "+sName+" board.\n",
        0, TP, ""); 
    move_object(TP, sRoom);
    if(iAutoCatchup && oBoard->query_new_posts())
        command("catchup", TP);
    else
        command("look at board", TP);
    say(TP->TNAME+" rushes in, takes a quick peek at the board and \
checks out the latest messages.\n", 0, TP, "");
    return 1;
}

int gotoBoard(string sStr) {
    string sName, sRoom;
    object oBoard;
    mixed  *xaTmp;

    notify_fail("Which board was that?\n");

    if(!sStr || sStr == "")
        return 0; 
    else
        xaTmp = queryNumList(sStr); 
    if(!xaTmp)
        xaTmp = queryNameList(sStr);
    if(!xaTmp)
        return 0;
    else
      sName = xaTmp[0];

    switch(xaTmp[1]) {
        case 0:
            sRoom = mCommon[sName][ROOM];
            oBoard = findBoard(mCommon, sName);
            break;
        case 1:
            sRoom = mGuild[sName][ROOM];
            oBoard = findBoard(mGuild, sName);
            break;
        case 2:
            sRoom = mWiz[sName][ROOM];
            oBoard = findBoard(mWiz, sName);
            break;
        default:
            return 0;
            break;
    }
    return gotoABoard(sRoom, sName, oBoard);
}

int filterCmd(string sStr) {
    string sName, sRoom;
    object oBoard;
    mixed  *xaTmp;

    xaTmp=queryAliasList(query_verb());
    if(!xaTmp)
        return 0;
    else
        sName = xaTmp[0];

    switch(xaTmp[1]) {
        case 0:
            sRoom = mCommon[sName][ROOM];
            oBoard = findBoard(mCommon, sName);
            break;
        case 1:
            sRoom = mGuild[sName][ROOM];
            oBoard = findBoard(mGuild, sName);
            break;
        case 2:
            sRoom = mWiz[sName][ROOM];
            oBoard = findBoard(mWiz, sName);
            break;
        default:
            return 0;
            break;
    }
    return gotoABoard(sRoom, sName, oBoard);
}

int newNotes() {
    string *saNew;
    object oBoard;

    saNew = ({});

    oBoard = findBoard(mGuild, "adv");
    if(oBoard && oBoard->query_new_posts())
        saNew += ({ "the "+mGuild["adv"][SDESC]});

    oBoard = findBoard(mCommon, "psheriff");
    if(oBoard && oBoard->query_new_posts())
        saNew += ({ "the "+mCommon["psheriff"][SDESC]});

    oBoard = findBoard(mCommon, "pflame");
    if(oBoard && oBoard->query_new_posts())
        saNew += ({ "the "+mCommon["pflame"][SDESC]});

    oBoard = findBoard(mCommon, "bugs");
    if(oBoard && oBoard->query_new_posts())
        saNew += ({ "the "+mCommon["bugs"][SDESC]});

    if(sizeof(saNew))
        printf("You sense that you have unread notes on %s\n",
               listArray(saNew));
    else
        write("You don't think that you have any unread notes on the \
main player boards.\n");
    return 1;
}

string displayBoardList(mapping mMap, string sMapName) {
    string sTmp, sLine, sRet, sNew, sShort;
    int    *iaNum, i, iNew, iFlag;
    object oRoom, oBoard;

    switch(sMapName) {
        case "Common":
            iFlag = 0;
            break;
        case "Guild":
            iFlag = 1;
            break;
        case "Wiz":
            iFlag = 2;
            break;
        default:
            return "";
            break;
    }

    sRet = "";
    iaNum = queryNumList()[iFlag];
    iaNum = filter_array(iaNum, lambda(({'i}), ({#'>, 'i, 0})));
    iaNum = sort_array(iaNum, #'>);
    for(i = 0; i < sizeof(iaNum); i++) {
        iNew = 0;
        sTmp = queryNumList(iaNum[i]+"")[0];
        sLine = "b "+sTmp+DOTS;
        sLine = sLine[0..10]+" ";
        sLine += sprintf("(b %2d) .. ", mMap[sTmp][NUM]);
        sLine += (mMap[sTmp][ALIAS] + DOTS);
        sLine = sLine[0..29]+" ";

        oBoard = findBoard(mMap, sTmp);
        if(oBoard) {
            sShort = (string)oBoard->SHORT;
            iNew = oBoard->query_new_posts();
        }
        else
            sShort = mMap[sTmp][SDESC];
        if(iNew)
            sNew = "N";
        else
            sNew = " ";
        if(!iNewOnly || iNew)
            sRet += sprintf(" %1s  %31s%-=43s\n", sNew, sLine, sShort);
    }
    if(sRet != "")
        sRet = sprintf("  %s boards:\n\n%s\n", sMapName, sRet);
    return sRet;
}

int get() {
    return 1;
}

int drop() {
    return 1;
}

void init_arg(string sStr) {
    if(sStr && sStr != "")
        sscanf(sStr, "%d", iAutoCatchup);
}

string query_auto_load() {
    return "/"+explode(file_name(TO), "#")[0]+":"+iAutoCatchup;
}

string short()   {
    return "Bboots (Board boots "+VERSION+") (worn)";
}

void long() {
    string sRet;

    if(iNewOnly)
        sRet = "";
    else
        sRet  = "Available boards:\n\n";
    sRet += displayBoardList(mCommon, "Common");
    sRet += displayBoardList(mGuild,  "Guild");
    sRet += displayBoardList(mWiz,    "Wiz");
    if(sRet == "")
        sRet = "No new posts.\n";  
    if(!iNewOnly)
        sRet += "Further commands:\n\tactivate <\"bboots\">, autocatchup, \
bsend <name>\n";
    TP->more_string(sRet);
}

void reset(int iArg) {
    if(!iArg) {
        sFilename= "/"+file_name(TO);
        sscanf(sFilename, "%s#%*d", sFilename);
//           name       : ({ #, alias, short,  room, object (enter as 0) })
        mCommon=([
            "psheriff" : ({ 1, "bps",  "Sheriff's office board",
                            "/room/player/sheriff", 0}),
            "bugs"     : ({ 2, "bbugs","Bugs board",
                            "/room/player/bug", 0}),
            "pflame"   : ({ 3, "bpf",  "Player flame board",
                            "/room/player/flame", 0}),
            "friend"   : ({ 4, "bfr",  "Friendship board",
                            "/players/rasta/room/bulletin", 0}),
            "fghant"   : ({ 5, "bsi",  "Town Hall board",
                            "/players/silas/fghant/ktownhall", 0}),
            "www"      : ({ 6, "bwww", "WWW board",
                            "/players/jewel/rooms/www", 0}),
            "prison"   : ({ 7, "bpr",  "Mage's prison board",
                            "/players/llort/guild/prison/prison", 0}),
            "layout"   : ({ 8, "blay", "New Layout Discussion board",
                            "/room/player/new_layout", 0}),
        ]);
        mGuild=([
            "adv"      : ({ 21, "badv", "Adventurers guild board",
                            "/room/adv_guild", 0}),
            "thief"    : ({ 22, "bth", "Thief's guild board",
                            "/players/brainsprain/guild/hideout", 0}),
            "druid"    : ({ 23, "bdr", "Druid's guild board",
                            "/players/meecham/guild/room", 0}),
            "fighter"  : ({ 24, "bfi", "Fighter's guild board",
                            "/players/sargon/guild/rooms/restroom", 0}),
            "jedi"     : ({ 25, "bje", "Jedi's guild board",
                            "/players/mangla/guild/rooms/inner", 0}),
            "mage"     : ({ 26, "bma", "Mage's guild board",
                            "/players/saffrin/area/tower/room/donation", 0}),
            "bard"     : ({ 27, "bba", "Bard's guild board",
                            "/players/turbo/guild/rooms/bard1", 0}),
            "monk"     : ({ 28, "bmk", "Monk's guild board",
                            "/players/whisky/guild/room/c10", 0}),
            "ninja"    : ({ 29, "bni", "Ninja's guild board",
                            "/players/tatsuo/ezo/empty", 0}),
            "summ"     : ({30, "bsu", "Summoner's guild board",
                            "/players/redsexy/guild/rooms/lounge", 0}),
            "vaga"     : ({ 31, "bva", "Vagabond's guild board",
                            "/players/nae/guild/room", 0}),
            "barb"     : ({ 32, "bbr", "Barbarian's guild board",
                            "/players/darastor/guild/room", 0}),
        ]);
        mWiz=([
            "inner"    : ({ 51, "bwiz", "Wiz general board",
                            "/room/wiz/general", 0}),
            "lpc"      : ({ 52, "blpc", "LPC board",
                            "/room/wiz/lpc", 0}),
            "wsheriff" : ({ 53, "bws", "Wiz's Sheriff board",
                            "/room/wiz/sheriff", 0}),
            "wflame"   : ({ 54, "bwf", "Wiz flame board",
                            "/room/wiz/flame", 0}),
            "illegal"  : ({ 55, "bill", "'Illegal' board",
                            "/room/wiz/illegal", 0}),
            "guilds"   : ({ 56, "bg", "Guilds board",
                            "/room/wiz/guild", 0}),
            "mentor"   : ({ 57, "bmn", "Mentor board",
                            "/room/wiz/approval", 0}),
            "idea"     : ({ 58, "bidea", "Ideas board",
                            "/room/wiz/idea", 0}),
        ]);
    }
}

void init() {
    if(!TP->IMM && !TP->TESTP) {
      if(ENV() == TP)
        write("You're not supposed to have these.\n");
      destruct(TO);
      return;
    }

    add_action("filterCmd",	"", 1);
    add_action("gotoBoard",	"b");
    add_action("activate",	"activate");
    add_action("autoCatchup",	"autocatchup");
    add_action("sendBoots",	"bsend");
}
