#include "Frog.hpp"


extern int groundSize;
extern int windowHeight;
extern int windowWidth;

Frog::Frog() {
	speed = 200.0f;

	model.Load("assets/models/frog/frog.3ds");
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = 142.0f;

	initialPos = pos;

	lives = 3;

	score = 0;

	moving = false;
	direction = Vector3f(0.0f, 0.0f, 1.0f);

}

Frog::Frog(float x, float y, float z) {

	speed = 200.0f;

	model.Load("assets/models/frog/frog.3ds");
	pos.x = x;
	pos.y = y;
	pos.z = z;

	initialPos = pos;

	lives = 3;

	score = 0;

	direction = Vector3f(0.0f, 0.0f, 1.0f);

	moving = false;

}

void Frog::resetPosition() {
	pos = initialPos;
	direction = Vector3f(0.0f, 0.0f, 1.0f);
	moving = false;

}

void Frog::takeDamage() {
	lives--;
}

void Frog::heal() {
	lives++;
}

int Frog::getLives() const {
	return lives;
}

int Frog::getScore() const {
	return score;
}

void Frog::addScore() {
	score += 100;
}

float Frog::getX() const { return pos.x; }
float Frog::getY() const { return pos.y; }
float Frog::getZ() const { return pos.z; }
float Frog::getSpeed() const { return speed; }

float Frog::getDirectionX() const { return direction.x; }
float Frog::getDirectionZ() const { return direction.z; }


// Toggle movement state
void Frog::setMoving(bool isMoving) {
	moving = isMoving;
}


// Move player forward
void Frog::moveForward() {
	direction = Vector3f(0.0f, 0.0f, -1.0f);
	setMoving(true);
}

// Move player backward
void Frog::moveBackward() {
	direction = Vector3f(0.0f, 0.0f, 1.0f);
	setMoving(true);
}

// Move player left
void Frog::moveLeft() {
	direction = Vector3f(-1.0f, 0.0f, 0.0f);
	setMoving(true);
}

// Move player right
void Frog::moveRight() {
	direction = Vector3f(1.0f, 0.0f, 0.0f);
	setMoving(true);
}

bool Frog::hasCollided(Vector3f pos, float radius) {
	// Calculate distance between player and object
	float distance = sqrt((pos.x - this->pos.x) * (pos.x - this->pos.x) +
		(pos.y - this->pos.y) * (pos.y - this->pos.y) +
		(pos.z - this->pos.z) * (pos.z - this->pos.z));

	// Check if the distance is less than the sum of the radii
	if (distance < radius + 1.0f) {
		return true;
	}
	return false;
}


void Frog::drawHeart(float x, float y, float size) {
	glBegin(GL_POLYGON);
	for (float angle = 0; angle < 2 * M_PI; angle += 0.1) {
		float a = size * (16 * pow(sin(angle), 3));
		float b = size * (13 * cos(angle) - 5 * cos(2 * angle) - 2 * cos(3 * angle) - cos(4 * angle));
		glVertex3f(x + a / 100.0f, y + b / 100.0f, 0.0);
	}
	glEnd();
}


void Frog::drawHealth() {
	glColor3f(1.0f, 0.0f, 0.0f);  // Red color for hearts

	// Position hearts near the top-left corner
	float heartX = windowWidth * 0.05f;  // 5% from the left (close to the left edge)
	float heartY = windowHeight * 0.90f; // 85% from the bottom (below the score)

	// Draw hearts for each life
	for (int i = 0; i < lives; i++) {
		drawHeart(heartX + (i * (windowWidth * 0.03f)), heartY, 100);  // Adjust heart spacing based on window width
	}
}

void Frog::drawScore() {
	glColor3f(1.0f, 1.0f, 1.0f);  // White color for text

	// Position score near the top-right corner
	float scoreX = windowWidth * 0.90f;  // 90% from the left (close to the right edge)
	float scoreY = windowHeight * 0.90f; // 90% from the bottom (below the score)

	// Draw the score
	glRasterPos2f(scoreX, scoreY);
	std::string scoreString = "Score: " + std::to_string(score);
	for (char c : scoreString) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	}
}

void Frog::renderHUD() {
	glDisable(GL_LIGHTING); // Disable lighting for 2D rendering
	glDisable(GL_DEPTH_TEST); // Disable depth test for HUD
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, windowWidth, 0, windowHeight);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	drawHealth();
	drawScore();

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	glDisable(GL_BLEND); // Disable blending
	glEnable(GL_DEPTH_TEST); // Re-enable depth test
	glEnable(GL_LIGHTING); // Re-enable lighting
}



void Frog::update(float deltaTime) {
	if (moving) {
		// Move player in the direction they are facing
		pos = pos + direction * speed * deltaTime;

		// Clamp player position to the game area

	}
}


void Frog::render() {
	glPushMatrix();
	// Apply transformations
	glTranslatef(pos.x, pos.y, pos.z);       // Translate to current position
	model.Draw();                         // Render the model
	glPopMatrix();
}


