/* Super Monstruelle ( Fran6 édition )
    Gouesnac'h / 15 fev 2020 / Pendant la Fran6LaLAN #12
    Team Slip
    
    arduino 1.8.5
      + lib. Arduboy2 version 5.2.1
      + ATMlib version 1.2.6

    Des gouttes de sang tombent du haut de l'écran, il faut les rattraper avec la cup
    si on les attrape : la jauge augmente (à droite)
    si on les rate : la culotte se tache (à gauche)
    ...

*/

#include <Arduboy2.h>
#include <ATMlib.h>
#include "bitmaps.h"
#include "song.h"

Arduboy2 arduboy;
Sprites sprites;
ATMsynth ATM;

byte gameState = 0;      // position par défaut : écran titre
boolean newPlay = true;  // utilisé pour remetre à zéro les variables

byte pos = 50;           // position entre 0 et 100;
byte level = 0;          // niveau : quel personnage
byte jauge = 0;          // état de la jauge : nombre de gouttes chopées sur ce niveau
byte slip = 0;           // état du slip : nombre de gouttes ratées

// Variables pour les joueur
int player_x, player_y;  // coordonnées sur l'écran

// Variables pour la goutte de sang
int blood_x, blood_y;    // cooordonnées sur l'écran 
int blood_dx, blood_dy;  // déplacement sur chaque axe



void setup() {

  player_x = adapterPosition(50);
  player_y = 50;

  blood_x = int( random(30, 110) );
  blood_y = 0;
  blood_dx = 0;
  blood_dy = 1;

  arduboy.begin();
  arduboy.initRandomSeed(); //Seed the random number generator
  arduboy.setFrameRate(40); //Set the game to 60 frames per second
  arduboy.audio.on();
  ATM.play(music);
  arduboy.clear();

}

void loop() {

  //Prevent the Arduboy from running too fast
  if (!arduboy.nextFrame()) {
    return;
  }
  arduboy.clear();
  arduboy.pollButtons();

  if ( (arduboy.justPressed(A_BUTTON)||arduboy.justPressed(B_BUTTON) ) && gameState == 0) gameState = 1; // Démarrer un partie (bouton A)
  if ( (arduboy.justPressed(A_BUTTON)||arduboy.justPressed(B_BUTTON) ) && gameState == 2) gameState = 0; // Revenir à l'écran titre
  if ( (arduboy.justPressed(A_BUTTON)||arduboy.justPressed(B_BUTTON) ) && gameState == 3) gameState = 0; // Revenir à l'écran titre

  // Uniquement pour les tests
  //if (arduboy.pressed(UP_BUTTON) && gameState == 1) gameState = 2; //
  //if (arduboy.pressed(DOWN_BUTTON) && gameState == 1) gameState = 3; //

  // Définir l'état du jeu *******************************************
  //   gameState = 0 : ecran titre
  //   gameState = 1 : jeu en cours
  //   gameState = 2 : fini et gagnant
  //   gameState = 3 : fini et perdu
  
  if ( gameState == 1 && slip > 3) gameState = 3;                 // GAME OVER!
  if ( gameState == 1 && jauge > 3 && level == 1) gameState = 2;  // WIN
  if ( gameState == 1 && jauge > 3 && level < 1) levelUp();       // LEVEL UP

  switch (gameState) {
    case 0:
      gameTitle();
      break;
    case 1:
      gamePlaying();
      break;
    case 2:
      gameOverWin();
      break;
    case 3:
      gameOverLost();
      break;
    default:
      break;
  }

  // *******************************************

  arduboy.display();

}

void gameTitle() {
  sprites.drawSelfMasked(0, 0, supermonstruelle, 0);
}

void gamePlaying() {

  if (newPlay) initNewPlay(); // Remettre à zéro si nécessaire
  
  // Afficher les portraits en haut à gauche
  if (level == 0) sprites.drawSelfMasked(0, 0, ursula, 0);
  if (level == 1) sprites.drawSelfMasked(0, 0, fran6lalan, 0);
  arduboy.fillRect(0, 16, 16, 32);

  // Afficher le nombre de gouttes ratées
  if (slip == 0) sprites.drawSelfMasked(0, 48, slip0, 0);
  if (slip == 1) sprites.drawSelfMasked(0, 48, slip1, 0);
  if (slip == 2) sprites.drawSelfMasked(0, 48, slip2, 0);
  if (slip == 3) sprites.drawSelfMasked(0, 48, slip3, 0);

  // afficher le nombre de gouttes attrapées
  if (jauge == 0) sprites.drawSelfMasked(120, 0, jauge0, 0);
  if (jauge == 1) sprites.drawSelfMasked(120, 0, jauge1, 0);
  if (jauge == 2) sprites.drawSelfMasked(120, 0, jauge2, 0);
  if (jauge == 3) sprites.drawSelfMasked(120, 0, jauge3, 0);

  // Adapter la position du player
  if (arduboy.pressed(LEFT_BUTTON)) pos -= 2;
  if (arduboy.pressed(RIGHT_BUTTON)) pos += 2;
  if (pos < 0) pos = 0;
  if (pos > 100) pos = 100;
  player_x = adapterPosition(pos);

  sprites.drawSelfMasked(player_x, player_y, cup, 0);

  // Déplacer et afficher la goutte de sang
  blood_x += blood_dx;
  blood_y += blood_dy;
  
  sprites.drawSelfMasked(blood_x, blood_y, blood, 0);

  // Test : a t'on attrapé la goutte ?
  float dd = dist(player_x, player_y, blood_x, blood_y);
  if (dd < 5) { // on marque un point
    jauge += 1;
    blood_y = 0;
    blood_x = int( random(30, 110) );
  }

  // Test : la goutte est elle sortie de l'écran ?
  boolean blood_is_out = false;
  if (blood_y > 50) blood_is_out = true;
  if (blood_is_out) {
    slip += 1;
    blood_y = 0;
    blood_x =  int( random(30, 110) );
  }
}

void gameOverWin() {
  sprites.drawSelfMasked(0, 0, win, 0);
  newPlay = true;
  initNewPlay();
}

void gameOverLost() {
  sprites.drawSelfMasked(0, 0, gameover, 0);
  newPlay = true;
  initNewPlay();
}

int adapterPosition(int p_) {
  return int( map(p_, 0, 100, 16, 112) );
}

void levelUp() {
  level ++;
  jauge = 0;
  slip = 0;
}

void initNewPlay() {
  pos = 50;
  jauge = 0;
  level = 0;
  slip = 0;
  newPlay = false;
}

int dist(int xa, int ya, int xb, int yb) {
  float d = sqrt ( ( (xa - xb) * (xa -xb) ) + ( (ya -yb) * (ya - yb) ) );
  return int(d);
}
