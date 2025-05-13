/* Cloud City Cell System 15 x 15 matrix to start ;) */

#include "/players/kbl/include/cell.h"
#include "/players/kbl/include/objs.h"

#define QIMM query_cloud_main_map()
#define QIOL query_cloud_overlay()

object *cel_total;
object limits;
mixed  *tdest;
int called;

query_cloud_main_map()
{
  return ({
       "x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x",
       "x","0","0","0","0","1","0","0","0","0","0","2","2","3","4","0","x",
       "x","0","1","0","0","1","1","0","2","5","4","2","0","3","4","4","x",
       "x","0","1","A","0","1","2","0","0","7","B","2","0","0","0","7","x",
       "x","0","0","B","9","D","3","0","0","8","B","1","0","0","0","7","x",
       "x","9","9","9","9","9","9","1","1","2","B","A","C","0","0","9","x",
       "x","9","1","1","1","1","9","1","0","3","B","A","C","0","0","A","x",
       "x","9","1","1","F","1","9","1","0","0","B","1","C","0","0","B","x",
       "x","9","2","2","F","1","9","0","0","0","B","0","E","0","0","0","x",
       "x","9","9","9","9","9","8","0","6","6","B","0","F","F","1","0","x",
       "x","0","0","0","0","9","9","1","6","4","0","0","0","0","2","0","x",
       "x","3","3","3","3","3","3","1","0","0","0","0","0","0","F","0","x",
       "x","1","0","0","0","5","5","1","0","0","0","9","8","7","0","0","x",
       "x","5","0","0","0","7","5","6","0","0","0","9","0","A","0","0","x",
       "x","8","0","0","0","0","0","6","0","0","0","A","1","1","1","1","x",
       "x","1","0","0","F","1","1","0","0","0","D","0","0","0","0","F","x",
       "x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x",
          });
}
/*  
INFO: query_cloud_main_map()

    Cell mapping of CCCS (Cloud City Cell System)

    1 - 9 and A - C, E & F: standard types of cells from description object
                     "/players/kbl/cloud/tds"->query_descrips()[<num>];
    D: Decell, description in tds.c Place where runners can actually come
               out in different area than where they "connected" at.
    0: Chaotic cells (random connections), not loaded a game time, generated
       by a function, called by a object that "throws" you there, per say ;)
*/

query_cloud_overlay()
{
  return ({
       "x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x",
       "x","G","G","G","Y","N","R","G","G","R","G","P","G","R","G","W","x",
       "x","G","R","G","Y","Y","R","R","R","R","Y","G","B","R","G","R","x",
       "x","B","R","B","Y","B","R","B","Y","Y","B","B","R","Y","W","Y","x",
       "x","R","R","R","R","Y","Y","B","B","Y","R","R","Y","Y","W","Y","x",
       "x","S","S","S","S","S","S","B","Z","Y","B","S","S","W","B","S","x",
       "x","S","R","R","G","B","S","R","W","Y","B","S","S","W","R","R","x",
       "x","S","R","R","H","B","S","R","W","R","B","R","S","W","B","V","x",
       "x","S","R","R","S","B","S","W","W","R","B","W","S","W","R","B","x",
       "x","S","S","S","S","S","S","W","Y","Y","B","W","S","S","G","G","x",
       "x","W","W","R","B","S","S","R","R","Y","Y","W","R","R","G","B","x",
       "x","R","R","R","R","B","R","R","W","W","R","W","R","R","S","B","x",
       "x","B","W","R","W","R","R","R","W","W","W","S","S","G","G","G","x",
       "x","B","B","W","Y","Y","R","B","Y","R","R","S","R","G","Y","Y","x",
       "x","S","R","W","R","Y","W","B","Y","G","B","S","R","B","R","R","x",
       "x","B","R","W","S","Y","Y","W","W","B","S","W","W","B","B","S","x",
       "x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x",
          });
}
/*
  INFO: query_cloud_overlay()

       Cell type colours: R (Red),   G (Green), 
                          B (Blue),  Y(Yellow)
       
       Special Cells: W (White), 
                      S (Guard)
                      H (Guard HQ),
                      V (Court Yard Entrance), 
                      N (Palace Entrance)
                      Z (Cell Club)

       Associated densities and accesses:

       G: Access  1-5     R: Access  6-12     Y: Access  10-17
          Density 1-5        Density 6-9         Density 8-13

       B: Access  15-21   S: Access  20-50    W: Access  1-21
          Density 11-18      Density 16-45       Density 1-18

       Note: (W) White chaotic cells will have random access and density
                 generated upon cloning. Only Chaotic cells can be white.
                 Also, these cells will have random node connections as
                 well.
*/

load_cells()
{
  int    i;
  int    max;

  if(!cel_total);
    init_cells();
  if(called)
  {
    tell_object(TP,"The Cells are already loaded!\n");
    return;
  }
  if(!called)
   called = 1;
  max = sizeof(TO->QIMM);
  for(i=0;i<max;i++)
  {
    switch(TO->QIMM[i])
    {
      case "x": /* Don't auto configure boundry cells */
      case "0": /* Don't auto configure chaotic cells */
          break;
      case "D": /* Create Decell Cell */   
          build_decell(i);
          break;
      default:
          gen_cell(i);
          break;
    }
  }
}
      
init_cells()
{
  int i;

  cel_total = ({});
  for(i=0;i<sizeof(TO->QIMM);i++)
    cel_total += ({CO(CELL)});
}

build_decell(n)
{
  switch(n)
  {
    case 33:
        setup_cell(n,"cde",29);  /* Setup Court Yard Decell Exit */
        break;
    case 265:
        setup_cell(n,"pde",31);  /* Setup Palace Decell Exit */
        break;
  }
}

gen_cell(n)
{
  
  switch(TO->QIOL[n]) /* Determine overlay type */
  {
    case "R":
        setup_cell(n,"std",1); /* Setup a standard cell */
        break;
    case "G":
        setup_cell(n,"std",3); /* Setup a standard cell */
        break;
    case "B":
        setup_cell(n,"std",5); /* Setup a standard cell */
        break;
    case "Y":
        setup_cell(n,"std",7); /* Setup a standard cell */
        break;
    case "W":
        setup_cell(n,"cha",9); /* Setup a chaotic cell */
        break;
    case "S":
        setup_cell(n,"gua",19); /* Setup guard cell */
        break;
    case "H":
        setup_cell(n,"ghq",21); /* Setup Guard HQ Cell */
        break;
    case "V":
        setup_cell(n,"cou",23); /* Court Yard Entrance Cell */
        break;
    case "N":
        setup_cell(n,"pal",25); /* Palace Entrance Cell */
        break;
    case "Z":
        setup_cell(n,"clb",27); /* Setup Cloud Cell Club */
        break;
  }
}

setup_cell(loc,config,desc)
{
  int *accden;
  int tmp_desc;

  accden = TAC(loc);

  /* Set up basic cell descriptions */

  cel_total[loc]->set_name(TDS(desc-1));
  cel_total[loc]->set_long(TDS(desc));
  cel_total[loc]->set_dest(fig_dest(loc,config));
  cel_total[loc]->set_access(random(accden[1])+accden[1]-accden[0]);
  cel_total[loc]->set_density(random(accden[3])+accden[3]-accden[2]);
  cel_total[loc]->set_conn(sizeof(cel_total[loc]->query_cell_dest())/2);
  cel_total[loc]->set_type(TYP(loc));
  cel_total[loc]->set_config(1);

/* Move cloud cells to room containment object */
  if(config == "cha")
   MO(cel_total[loc],CHACEL);
  else
   MO(cel_total[loc],ALLCEL);

/* Clone objects and setup special cells */
  switch(config)
  {
    case "clb": MCO(HEAL_OBJ,cel_total[loc]);  /* Clone heal dispenser */
                MCO(SHOP_OBJ,cel_total[loc]);  /* Clone shop object */ 
                break;
    case "cha": if((tmp_desc = random(10)) % 2)
                   tmp_desc += 1;
                cel_total[loc]->set_long(TDS(desc+tmp_desc));                 
        /* Clone objects for standard and chaotic cells */
    case "std": if(random(random(random(100))) > 75)
                  RCO(cel_total[loc]);
                break;
    case "gua": MCO(SECU_OBJ,cel_total[loc]);  /* Clone a cell monitor */
                break;
    case "ghq": MCO(SEHQ_OBJ,cel_total[loc]);  /* Clone HQ object */
                MCO(IXSO_OBJ,cel_total[loc]);  /* Clone Guard Chief */
                break; 
    case "pal": tmp = CO(CCPB_OBJ);            /* Clone Palace board */
                tmp->set_board_name("Cloud City Palace board");
                tmp->set_file(CCPB_BRD);
                tmp->set_level(50);
                MO(tmp,cel_total[loc]);
                break;
    case "cou": tmp = CO(CCCY_OBJ);            /* Clone Court Yard board */
                tmp->set_board_name("Cloud City Court Yard board");
                tmp->set_file(CCCY_BRD);
                tmp->set_level(50);
                MO(tmp,cel_total[loc]);
                break;
    case "pde": tmp = CO(PDEL_OBJ);            /* Clone Palace decell */
                tmp->set_trans_to(PALA_ENT);
                tmp->set_descrip("Bright blue ball");
                tmp->set_access(10);
                tmp->set_color("bright blue");
                tmp->set_place("Cloud City Palace Entrance");
                MO(tmp,cel_total[loc]);
                break;
    case "cde": tmp = CO(CDEL_OBJ);            /* Clone Court Yard decell */
                tmp->set_trans_to(COUR_ENT);
                tmp->set_descrip("Soft red ball");
                tmp->set_access(10);
                tmp->set_color("soft red");
                tmp->set_place("Cloud City Court Yard");
                MO(tmp,cel_total[loc]);
                break;
  }
}    

/* 
   NOTE: In above the following applies:

   TDS(n) = "/d/Ix/obj/cells/tds"->query_descrips()[n]
   TAC(n) = "/d/Ix/obj/cells/tac"->query_accden(n)
   TYP(n) = "/d/Ix/obj/cells/typ"->query_types(n)
*/

mixed *fig_dest(loc,con)
{
  int lim;
  int range;

  lim = ROW_MAX;
  range = CEL_RANGE;
  tdest = ({});
  if(con == "cha") /* Generate chaotic range for mapping chaotic cells */
  {
   range = random(sizeof(TO->QIMM)) - loc;
   if(range < 1)
    range = random(ROW_MAX + loc);
   while(range + loc + lim > sizeof(TO->QIMM))
     range = random(range);
  }
  if(TO->QIMM[loc+range] != "0" || TO->QIMM[loc+range] != "x")
    tdest+=({"CELL"+(loc+range),cel_total[loc+range]});
  if(TO->QIMM[loc-range] != "0" || TO->QIMM[loc-range] != "x")
    tdest+=({"CELL"+(loc-range),cel_total[loc-range]});
  if(TO->QIMM[loc+lim] != "0" || TO->QIMM[loc+lim] != "x")
    tdest+=({"CELL"+(loc+lim),cel_total[loc+lim]});
  if(TO->QIMM[loc-lim] != "0" || TO->QIMM[loc-lim] != "x")
    tdest+=({"CELL"+(loc-lim),cel_total[loc-lim]});
  if(TO->QIMM[loc+lim+range] != "0" || TO->QIMM[loc+lim+range] != "x")
    tdest+=({"CELL"+(loc+lim+range),cel_total[loc+lim+range]});
  if(TO->QIMM[loc+lim-range] != "0" || TO->QIMM[loc+lim-range] != "x")
    tdest+=({"CELL"+(loc+lim-range),cel_total[loc+lim-range]});
  if(TO->QIMM[loc-lim+range] != "0" || TO->QIMM[loc-lim+range] != "x")
    tdest+=({"CELL"+(loc-lim+range),cel_total[loc-lim+range]});
  if(TO->QIMM[loc-lim-range] != "0" || TO->QIMM[loc-lim-range] != "x")
    tdest+=({"CELL"+(loc-lim-range),cel_total[loc-lim-range]});
  if(!tdest)
   tdest+=({"ABST",limits});
  return tdest;
}

set_limit_cell(ob)
{
  limits = ob;
}
