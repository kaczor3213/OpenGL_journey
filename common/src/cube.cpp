#include "../include/cube.hpp"
#include <iostream>

Cube::Cube()
{
	coordinates.resize(36);
}

void Cube::generate()
{
	//zrob to, ma bolec, ale masz to zrobic lomie

////////

	coordinates[0].set_color(COLOR_GREEN);
	coordinates[1].set_color(COLOR_BLACK);
	coordinates[2].set_color(COLOR_RED);
	coordinates[3].set_color(COLOR_BLUE);

	coordinates[4].set_color(COLOR_GREEN);
	coordinates[5].set_color(COLOR_BLACK);
	coordinates[6].set_color(COLOR_RED);
	coordinates[7].set_color(COLOR_BLUE);

	coordinates[8].set_color(COLOR_GREEN);
	coordinates[9].set_color(COLOR_BLACK);
	coordinates[10].set_color(COLOR_RED);
	coordinates[11].set_color(COLOR_BLUE);

	coordinates[12].set_color(COLOR_GREEN);
	coordinates[13].set_color(COLOR_BLACK);
	coordinates[14].set_color(COLOR_RED);
	coordinates[15].set_color(COLOR_BLUE);

	coordinates[16].set_color(COLOR_GREEN);
	coordinates[17].set_color(COLOR_BLACK);
	coordinates[18].set_color(COLOR_RED);
	coordinates[19].set_color(COLOR_BLUE);

	coordinates[20].set_color(COLOR_GREEN);
	coordinates[21].set_color(COLOR_BLACK);
	coordinates[22].set_color(COLOR_RED);
	coordinates[23].set_color(COLOR_BLUE);

	coordinates[24].set_color(COLOR_GREEN);
	coordinates[25].set_color(COLOR_BLACK);
	coordinates[26].set_color(COLOR_RED);
	coordinates[27].set_color(COLOR_BLUE);

	coordinates[28].set_color(COLOR_GREEN);
	coordinates[29].set_color(COLOR_BLACK);
	coordinates[30].set_color(COLOR_RED);
	coordinates[31].set_color(COLOR_BLUE);

	coordinates[32].set_color(COLOR_GREEN);
	coordinates[33].set_color(COLOR_BLACK);
	coordinates[34].set_color(COLOR_RED);
	coordinates[35].set_color(COLOR_BLUE);
}

void Cube::render_cube()
{
	render();
	buff_handle();
}

void Cube::draw()
{
	run();
	transformLoc = glGetUniformLocation(shaderProgram, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
	viewLoc = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	projectionLoc = glGetUniformLocation(shaderProgram, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}