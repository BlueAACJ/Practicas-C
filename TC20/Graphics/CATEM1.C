#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

/* Programa hecho por Maria Felix Herrera Tablada
   Grupo 2m5Co

      */

int nube1[]={ 52,174, 37,176, 22,172, 3,168, 7,159, 17,156, 29,152, 45,149,
			  61,146, 73,150, 86,146, 98,149, 115,145, 128,149, 140,154,
			  134,160, 142,164, 123,167, 114,173, 96,172, 79,177, 61,177,
			  52,174 };


int nube2[]={ 102,87, 83,85, 72,83, 55,80, 57,74, 50,69,
	    63,67, 74,59, 97,60,
	    110,55, 122,58, 135,54, 145,61, 160,54, 173,59, 185,65, 180,50,
	     187,75, 171,79, 157,84, 143,83, 124,90, 102,87 };



int nube3[]={ 276,44, 258,44, 245,37, 243,29, 250,27, 260,20, 273,23, 284,22,
			  291,21, 302,17, 307,22, 321,17, 331,28, 334,33, 324,38, 316,44,
			  304,42, 291,48, 276,44 };


int nube4[]={ 516,56, 500,57, 488,52, 487,43, 497,42, 502,36, 514,39, 522,37,
			  530,38, 538,33, 547,37, 558,34, 567,42, 558,51, 549,57, 541,54,
			  529,61, 516,56 };

int nube5[]={ 589,161, 575,163, 566,156, 565,148, 574,143, 588,146, 597,140,
			  605,143, 616,140, 629,144, 631,155, 624,159, 617,161, 608,160,
			  598,165, 589,161 };



int nube6[]={ 585,247, 568,246, 560,242, 559,236, 572,233, 585,236, 596,232,
			  612,233, 625,229, 634,235, 637,244, 627,246, 612,245, 602,250,
			  585,244 };

int arb_izq[]={ 0,347, 17,354, 32,366, 42,370, 59,365, 77,360, 97,360,
				108,372, 133,368, 149,364, 172,356, 180,371, 186,393,
				190,420, 195,425, 200,430, 220,430, 220,445, 181,445,
				0,445, 0,347 };

int arb_der[]={ 405,430, 466,401, 470,383, 513,360, 540,362, 563,357,
				   583,361, 600,358, 620,365, 640,365, 640,445, 405,445,
				   405,430 };


int palmera1[]={116,435,116,414,117,365,117,341,119,298,122,298,
		123,329,122,354,121,390,121,435,116,435};

int palmera2[]={157,430,160,298,164,298,161,372,161,430,157,430};

int palmera3[]={496,425,496,299,502,299,502,425,496,425};

int hojasp1[]={118,305,111,311,104,321,100,329,101,321,102,313,
		94,320,87,318,91,304,84,310,83,304,88,296,
		98,293,108,292,115,292,104,283,88,272,100,270,111,273,
		117,280,116,297,117,255,125,267,125,282,136,274,
		152,272,145,282,142,288,151,295,159,304,145,303,
		137,303,147,315,150,327,136,312,139,324,141,331,
		128,316,127,334,118,305};

int hojasp2[]={163,295,158,303,154,312,153,301,146,306,149,297,
		139,298,148,290,159,286,142,276,155,274,145,268,
		155,267,159,271,169,258,167,266,178,267,171,272,
		184,266,168,287,184,284,192,297,177,292,193,306,
		179,302,178,314,166,303,159,314,163,295};


int hojasp3[]={485,304,472,335,474,309,463,322,468,304,458,308,
		460,300,452,302,468,287,480,284,489,285,468,274,
		481,268,471,254,489,260,493,246,497,272,518,252,
		500,283,518,274,539,284,525,281,537,297,519,293,
		530,312,531,331,506,298,506,325,500,316,494,350,
		489,317,484,327,485,304};


void main(void)
{

	int driver=DETECT,modo;
	int 	 gm, area, temp1, temp2, left = 25, top = 75;
	void *p,*q;

	initgraph(&driver,&modo,"c:\\TC20\\BIN");
	cleardevice();

setcolor(LIGHTBLUE);
setfillstyle(SOLID_FILL,LIGHTBLUE);
bar(1,1,639,479);

	/*Esqueleto*/

	setcolor(DARKGRAY);
setfillstyle(SOLID_FILL,DARKGRAY);
rectangle(221,419,404,443);
rectangle(226,347,233,417);
rectangle(259,348,267,417);
rectangle(293,347,301,418);
rectangle(327,347,335,418);
rectangle(361,346,369,417);

rectangle(394,344,403,418);
rectangle(223,418,237,411);
rectangle(254,418,271,411);
rectangle(290,418,306,411);
rectangle(325,420,340,411);
rectangle(357,418,373,410);
rectangle(391,420,407,409);
rectangle(224,342,404,346);
rectangle(229,341,396,331);
rectangle(216,326,411,330);
rectangle(227,327,400,318);
rectangle(243,389,260,390);
rectangle(433,392,434,392);
rectangle(274,390,292,392);
rectangle(306,390,328,388);
rectangle(340,388,351,389);
rectangle(357,390,338,392);
rectangle(372,388,389,391);
rectangle(245,356,255,364);
rectangle(310,356,319,363);
rectangle(374,355,385,363);
rectangle(243,391,252,417);
rectangle(275,394,275,394);
rectangle(275,393,287,418);
rectangle(309,393,316,407);
rectangle(319,408,319,409);

rectangle(308,392,321,417);
rectangle(343,395,354,417);
rectangle(376,394,387,416);
rectangle(200,441,200,441);
rectangle(197,435,205,446);
rectangle(206,435,208,447);
rectangle(406,431,414,440);
rectangle(244,317,259,288);
rectangle(276,289,291,318);
rectangle(307,290,321,317);
rectangle(338,290,354,318);
rectangle(370,290,385,318);
rectangle(415,290,429,320);
rectangle(201,295,216,323);
rectangle(222,281,227,326);
rectangle(234,281,238,318);
rectangle(266,280,270,318);
rectangle(296,280,300,317);
rectangle(328,279,332,318);
rectangle(361,278,365,317);
rectangle(392,278,396,318);
rectangle(404,278,408,323);
rectangle(436,278,440,326);
rectangle(448,278,452,326);
rectangle(140,214,140,214);
rectangle(232,278,240,281);
rectangle(221,278,229,281);
rectangle(192,281,195,293);

rectangle(193,282,197,324);
rectangle(181,282,184,323);
rectangle(180,280,185,282);
rectangle(193,279,198,283);
rectangle(265,277,271,281);
rectangle(295,276,302,279);
rectangle(328,276,334,278);
rectangle(359,275,366,279);
rectangle(391,274,397,277);
rectangle(403,273,411,276);
rectangle(433,273,441,277);
rectangle(447,275,453,278);
rectangle(180,273,454,317);
rectangle(177,318,215,348);
rectangle(175,350,222,432);
rectangle(412,318,426,331);
rectangle(436,335,438,336);
rectangle(412,318,455,346);
rectangle(413,347,463,428);
rectangle(406,346,412,350);
rectangle(404,350,412,354);
rectangle(417,384,434,406);
rectangle(415,385,436,408);
rectangle(199,387,215,408);
rectangle(196,387,217,410);
rectangle(178,352,183,411);
rectangle(195,354,217,371);
rectangle(191,353,220,374);
rectangle(212,411,219,420);
setcolor(LIGHTGRAY);
setfillstyle(SOLID_FILL,LIGHTGRAY);
rectangle(226,421,402,423);
rectangle(224,424,404,426);
rectangle(223,428,407,430);
rectangle(222,432,407,434);
rectangle(222,436,410,438);
rectangle(222,440,411,442);
rectangle(181,275,455,266);
rectangle(179,272,456,260);
rectangle(241,260,243,265);
rectangle(246,260,249,266);
rectangle(252,261,255,265);
rectangle(371,261,373,266);
rectangle(376,261,378,266);
rectangle(381,261,383,266);
rectangle(185,256,248,212);
rectangle(243,213,244,256);
rectangle(196,213,199,255);
rectangle(225,213,228,255);
rectangle(204,231,219,255);
rectangle(180,261,278,256);
rectangle(350,254,453,260);
rectangle(387,254,387,215);
rectangle(387,215,387,217);
rectangle(387,255,448,208);
rectangle(400,210,403,254);
rectangle(432,210,432,210);
rectangle(432,210,435,253);
rectangle(436,253,436,253);
rectangle(389,213,400,216);
rectangle(405,213,431,215);
rectangle(437,215,447,217);
rectangle(411,229,428,253);
rectangle(382,222,388,207);
rectangle(383,207,451,204);
rectangle(248,225,252,208);
rectangle(181,213,252,208);
rectangle(201,209,237,175);
rectangle(394,204,433,171);
rectangle(465,358,473,361);
rectangle(465,361,466,379);
rectangle(470,378,470,379);
rectangle(465,361,470,426);
rectangle(239,350,257,373);
rectangle(272,355,290,372);
rectangle(305,352,324,371);
rectangle(338,352,358,371);
rectangle(372,350,391,371);

line(339,389,344,378);
line(353,379,358,388);
line(345,379,354,379);
line(358,388,360,391);
line(376,380,370,392);
line(385,380,392,393);
line(377,380,387,380);
line(311,379,307,389);
line(322,381,327,390);
line(311,379,323,379);
line(322,380,324,382);
line(277,381,273,389);
line(288,382,291,391);
line(278,382,288,382);
line(246,382,241,388);
line(256,384,258,389);
line(245,384,257,384);
line(201,379,197,388);
line(214,380,217,387);
line(202,380,215,380);
line(313,241,278,260);
line(315,241,351,259);
line(315,242,315,242);
line(315,242,291,260);
line(317,242,336,260);
line(281,290,281,316);
line(287,290,287,317);
line(277,293,291,293);
line(277,301,291,301);
line(277,308,291,308);
line(308,291,323,306);
line(314,291,322,299);
line(307,304,321,317);
line(308,300,322,314);
line(315,291,308,304);
line(321,292,308,316);
line(321,305,314,316);
line(317,242,312,242);

ellipse(219,170,0,360,24,6);
ellipse(415,162,0,360,26,8);
rectangle(310,243,320,238);
rectangle(312,238,317,225);
rectangle(410,125,410,126);
rectangle(411,154,415,134);
rectangle(403,142,422,144);
rectangle(216,163,220,159);
rectangle(212,193,219,208);
rectangle(411,203,416,189);
rectangle(227,177,230,207);
rectangle(206,178,208,208);
rectangle(399,171,401,203);
rectangle(424,172,424,172);
rectangle(424,172,427,203);
rectangle(186,219,196,222);
rectangle(201,216,223,219);
rectangle(229,218,242,221);
rectangle(349,257,352,244);
rectangle(349,244,343,249);
ellipse(314,286,0,360,8,4);
ellipse(283,286,0,360,7,2);
ellipse(346,287,0,360,8,3);
ellipse(422,286,0,360,9,3);
ellipse(208,292,0,360,8,2);
ellipse(439,347,0,360,3,0);
bar(437,347,439,348);
rectangle(436,348,443,410);
rectangle(443,410,443,415);

/*PARTE DE COLORES*/
	setcolor(LIGHTGRAY);
setfillstyle(SOLID_FILL,LIGHTGRAY);
rectangle(176,349,464,430);
bar(178,350,466,430);
bar(178,348,455,319);
bar(179,349,451,331);
bar(180,316,454,275);
bar(174,274,458,264);
bar(185,256,249,213);
bar(388,210,448,254);
bar(389,165,413,172);
bar(429,182,429,182);
bar(389,165,441,204);
bar(196,169,242,208);
setcolor(DARKGRAY);
setfillstyle(SOLID_FILL,DARKGRAY);
bar(224,348,231,419);
bar(258,347,266,420);
bar(225,346,401,330);
bar(257,345,267,351);
bar(220,345,234,350);
bar(293,346,302,420);
bar(289,345,305,350);
bar(324,346,334,421);
bar(320,344,339,350);
bar(358,345,367,420);
bar(353,345,372,351);
bar(392,345,401,419);
bar(387,343,404,350);
setcolor(BLACK);
setfillstyle(SOLID_FILL,BLACK);
bar(275,290,291,316);
bar(306,291,322,316);
bar(338,290,355,317);
bar(241,391,254,395);
bar(256,399,256,399);
bar(242,391,257,417);
bar(275,393,290,419);
bar(307,392,323,420);
bar(339,393,357,419);
bar(373,392,389,420);
bar(246,357,256,366);
bar(311,357,311,358);
bar(374,355,385,363);
setcolor(CYAN);
setfillstyle(SOLID_FILL,CYAN);
bar(310,356,319,364);
setcolor(DARKGRAY);
setfillstyle(SOLID_FILL,DARKGRAY);
bar(419,407,434,394);
bar(198,408,214,389);
bar(221,275,226,316);
bar(234,274,240,316);
bar(266,280,271,316);
bar(296,281,301,316);
bar(329,279,334,316);
bar(360,278,366,316);
bar(389,275,396,317);
bar(403,274,408,318);
bar(435,275,440,316);
bar(191,279,196,315);
bar(196,315,196,315);
bar(196,315,190,318);
bar(185,274,200,279);
bar(218,274,229,277);
bar(233,274,243,278);
bar(259,274,275,280);
bar(291,275,305,281);
bar(324,274,338,281);
bar(354,274,369,280);
bar(351,255,453,260);
bar(181,257,181,257);
bar(181,257,278,261);
bar(180,261,458,265);
setcolor(BLACK);
setfillstyle(SOLID_FILL,BLACK);
bar(418,408,435,392);
ellipse(250,388,0,360,7,4);
ellipse(283,390,0,360,6,4);
ellipse(316,390,0,360,8,4);
ellipse(347,389,0,360,8,4);
ellipse(382,388,0,360,8,4);
ellipse(427,390,0,360,8,4);
ellipse(206,386,0,360,8,4);
bar(197,387,214,409);
bar(374,391,389,393);
bar(341,390,356,395);
bar(341,391,340,394);
bar(305,390,307,390);
bar(307,390,323,394);
bar(274,391,290,395);
bar(243,390,258,393);
ellipse(209,291,0,360,8,4);
ellipse(421,285,0,360,6,4);
ellipse(212,232,0,360,8,4);
ellipse(419,224,0,360,8,5);
bar(203,234,222,257);
bar(411,226,428,254);
bar(201,293,218,316);
bar(414,287,430,316);
bar(182,257,278,263);
bar(350,255,454,261);
setcolor(DARKGRAY);
setfillstyle(SOLID_FILL,DARKGRAY);
bar(369,256,373,260);
bar(379,256,386,260);
bar(386,260,386,260);
bar(247,257,251,262);
bar(259,257,264,264);
bar(413,349,433,370);
bar(196,352,217,370);
bar(185,218,197,223);
bar(204,216,221,221);
bar(230,217,243,222);
bar(243,212,248,257);
bar(222,213,228,257);
bar(198,211,204,257);
bar(388,216,400,221);
bar(406,212,431,217);
bar(439,219,449,222);
bar(432,209,438,255);
bar(400,211,406,256);
bar(386,275,398,278);
bar(401,274,411,280);
bar(431,276,443,278);
setcolor(BLACK);
setfillstyle(SOLID_FILL,BLACK);
bar(208,210,221,187);
setcolor(DARKGRAY);
setfillstyle(SOLID_FILL,DARKGRAY);
bar(195,207,242,168);
bar(388,204,441,163);
setcolor(LIGHTGRAY);
setfillstyle(SOLID_FILL,LIGHTGRAY);
setcolor(BLACK);
setfillstyle(SOLID_FILL,BLACK);
bar(208,210,221,185);
bar(406,205,420,177);
bar(216,163,220,159);
setcolor(BLACK);
setfillstyle(SOLID_FILL,BLACK);
setcolor(LIGHTGRAY);
setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(412,153,416,135);
bar(404,142,424,144);
bar(227,169,230,208);
bar(201,167,205,206);
bar(205,206,204,206);
bar(393,163,396,205);
bar(426,164,429,205);
setcolor(DARKGRAY);
setfillstyle(SOLID_FILL,DARKGRAY);
rectangle(239,354,259,371);
rectangle(271,353,290,372);
rectangle(305,349,325,371);
rectangle(340,351,357,371);
rectangle(371,351,389,372);
bar(209,190,221,189);
bar(209,193,220,194);
bar(209,196,221,197);
bar(209,200,221,201);
bar(209,203,221,204);
bar(412,231,429,232);
bar(412,236,428,237);
bar(412,240,428,241);
bar(412,243,428,244);
bar(412,246,428,247);
bar(412,250,428,251);
bar(381,280,381,280);
bar(205,235,222,236);
bar(205,238,222,239);
bar(205,241,222,242);
bar(206,244,222,245);
bar(205,247,223,248);
bar(205,251,222,252);
bar(278,290,279,317);
bar(285,291,286,317);
bar(276,296,292,295);
bar(276,301,291,302);
bar(276,307,291,308);
bar(181,315,454,319);
bar(313,226,317,238);
bar(312,239,319,242);
bar(216,326,409,331);
bar(227,327,399,318);
bar(409,328,455,331);
bar(437,330,443,424);
bar(438,421,443,431);
rectangle(178,332,225,335);
rectangle(177,347,222,349);
rectangle(401,332,437,334);
rectangle(404,345,437,347);
ellipse(276,294,0,360,0,2);
setcolor(BLACK);
setfillstyle(SOLID_FILL,BLACK);
ellipse(283,289,0,360,8,3);
ellipse(314,290,0,360,8,2);
ellipse(347,289,0,360,8,2);
ellipse(252,288,0,360,8,4);
ellipse(378,285,0,360,8,4);
bar(244,290,255,292);
bar(259,293,253,291);
setcolor(DARKGRAY);
setfillstyle(SOLID_FILL,DARKGRAY);
bar(243,291,260,316);
bar(371,286,385,318);
bar(283,286,286,275);
bar(312,287,316,276);
bar(344,287,348,275);
bar(375,283,380,275);
bar(418,282,423,275);
bar(207,287,212,276);
bar(212,276,212,274);
bar(180,351,183,431);
setcolor(YELLOW);
setfillstyle(SOLID_FILL,YELLOW);
bar(44,446,577,448);
setcolor(DARKGRAY);
setfillstyle(SOLID_FILL,DARKGRAY);
bar(43,449,577,482);
setcolor(YELLOW);
setfillstyle(SOLID_FILL,YELLOW);
bar(43,446,577,448);
bar(43,445,577,450);

setcolor(DARKGRAY);
setfillstyle(SOLID_FILL,DARKGRAY);
line(201,294,219,312);
line(209,293,218,302);
line(203,304,212,314);
line(210,294,203,304);
line(215,297,203,311);
line(216,303,207,315);
line(307,293,321,307);
line(314,293,321,300);
line(309,302,320,313);
line(316,294,308,302);
line(321,298,311,311);
line(322,306,317,312);
line(339,291,353,302);

line(340,291,354,307);
line(340,299,350,313);
line(347,291,354,298);
line(351,292,341,306);
line(353,299,344,311);
line(415,287,430,303);
line(416,296,428,307);
line(416,304,426,314);
line(423,289,416,301);
line(429,294,419,308);
line(429,305,424,312);
line(419,394,435,394);
line(419,398,435,398);
line(420,403,432,403);
line(199,391,212,391);
line(199,394,214,394);
line(199,398,213,398);
line(200,403,213,403);


setcolor(DARKGRAY);
setfillstyle(SOLID_FILL,DARKGRAY);
line(244,392,244,392);
line(244,392,244,392);
line(246,395,246,395);
line(242,393,258,410);
line(249,393,255,403);
line(242,403,256,417);
line(243,410,251,418);
line(251,392,242,399);
line(256,397,242,410);
line(256,409,246,417);
line(275,392,289,406);
line(275,403,290,418);
line(287,392,275,405);
line(289,402,275,416);
line(308,393,324,409);
line(308,403,321,416);
line(316,392,309,405);
line(322,398,308,415);
line(322,409,313,418);
line(343,391,357,405);
line(340,396,355,411);
line(340,407,348,415);
line(351,391,341,405);
line(356,401,345,416);
line(373,393,388,409);
line(382,392,390,400);
line(374,405,387,417);
line(382,392,375,406);
line(389,398,377,417);
bar(44,422,83,425);
bar(83,426,130,429);
setcolor(BROWN);
setfillstyle(SOLID_FILL,BROWN);
bar(44,426,83,444);
bar(84,431,130,445);
setcolor(DARKGRAY);
setfillstyle(SOLID_FILL,DARKGRAY);
bar(45,437,49,444);
bar(53,436,57,444);
bar(70,381,72,445);
bar(114,373,110,445);
setcolor(DARKGRAY);
setfillstyle(SOLID_FILL,DARKGRAY);
bar(181,208,253,213);
bar(250,213,251,225);
bar(381,208,387,222);
bar(383,205,452,207);
bar(467,358,473,361);
bar(468,362,465,427);
bar(467,362,473,427);
bar(249,214,254,225);
bar(344,244,351,249);
bar(350,245,353,254);

setcolor(YELLOW);
setfillstyle(SOLID_FILL,YELLOW);
bar(555,445,638,450);
bar(43,446,-1,450);
bar(1,447,49,445);
setcolor(DARKGRAY);
setfillstyle(SOLID_FILL,DARKGRAY);
bar(577,451,641,479);
bar(637,457,576,450);
bar(45,451,0,479);
bar(47,454,-4,450);



/*Dibujo de palmeras*/

	setlinestyle(0,1,1);
	fillpoly(10,palmera1);
	fillpoly(5,palmera2);
	fillpoly(4,palmera3);

	setcolor(GREEN);
	setlinestyle(0,1,1);
	fillpoly(28,hojasp2);
	fillpoly(40,hojasp1);
	fillpoly(32,hojasp3);
	setfillstyle(1,GREEN);
	floodfill(168,297,GREEN);
	floodfill(108,296,GREEN);
	floodfill(487,291,GREEN);


/*
   setcolor(YELLOW);
   circle(50, 100, 25);
   setfillstyle(SOLID_FILL, YELLOW);
   floodfill(50, 100, YELLOW);

   setcolor(BLACK);
   setfillstyle(SOLID_FILL, BLACK);
   fillellipse(44, 85, 2, 6);
   fillellipse(56, 85, 2, 6);

   ellipse(50, 100, 205, 335, 20, 9);
   ellipse(50, 100, 205, 335, 20, 10);
   ellipse(50, 100, 205, 335, 20, 11);
  */
   left=40;
   top=50;   /* 34*/

   area = imagesize(left, top, left + 160, top + 40);
   p = (void *)malloc(area);
   q = (void *)malloc(area);

  /* setcolor(WHITE);
   settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
   outtextxy(155, 451, "Smiling Face Animation");

   setcolor(BLUE);
   rectangle(0, 0, 639, 449);
    */

	setcolor(WHITE);
	fillpoly(22,nube1);
	fillpoly(22,nube2);
	fillpoly(18,nube3);
	fillpoly(17,nube4);
	fillpoly(15,nube5);
	fillpoly(14,nube6);
	setfillstyle(1,WHITE);
	floodfill(70,165, WHITE); /*70,165   */
	floodfill(127,73, WHITE); /*127,53   */
	floodfill(291,28, WHITE);
	floodfill(533,50, WHITE);
	floodfill(603,151, WHITE);
	floodfill(601,241, WHITE);

	/* Dibujando los arbustos */
	setcolor(GREEN);
	fillpoly(20,arb_izq);
	fillpoly(12,arb_der);
	setfillstyle(1,GREEN);
	floodfill(59,379,GREEN);
	floodfill(599,376,GREEN);
	getimage(left+150, top, left + 300, top + 40, q);
	while(!kbhit())
   {
      temp1 = left + 10;
      temp2 = top ;
      /* Moviendo la nube 2 */
      getimage(left, top, left + 160, top + 40, p); /*capturar imagen de fondo*/
      putimage(left, top, q, COPY_PUT);/*poner la imagen de fondo*/
      putimage(temp1 , temp2, p	, COPY_PUT);/*poner nube en la nueva posicion*/
      delay(2000);
      left = temp1;
      top = temp2;
      }







	getch();
	closegraph();
}