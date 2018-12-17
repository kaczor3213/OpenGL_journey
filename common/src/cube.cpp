#include "../include/cube.hpp"
#include <iostream>

cube::cube()
{
	coordinates.resize(36);
}

void cube::generate()
{
	coordinates[0].position[0] = -0.5;
	coordinates[0].position[1] = -0.5;
	coordinates[0].position[2] = -0.5;

	coordinates[1].position[0] = 0.5;
	coordinates[1].position[1] = -0.5;
	coordinates[1].position[2] = -0.5;

	coordinates[2].position[0] = 0.5;
	coordinates[2].position[1] = 0.5;
	coordinates[2].position[2] = -0.5;

	coordinates[3].position[0] = 0.5;
	coordinates[3].position[1] = 0.5;
	coordinates[3].position[2] = -0.5;

	coordinates[4].position[0] = -0.5;
	coordinates[4].position[1] = 0.5;
	coordinates[4].position[2] = -0.5;
	
	coordinates[5].position[0] = -0.5;
	coordinates[5].position[1] = -0.5;
	coordinates[5].position[2] = -0.5;
	
	coordinates[6].position[0] = -0.5;
	coordinates[6].position[1] = -0.5;
	coordinates[6].position[2] = 0.5;
	
	coordinates[7].position[0] = 0.5;
	coordinates[7].position[1] = -0.5;
	coordinates[7].position[2] = 0.5;
	
	coordinates[8].position[0] = 0.5;
	coordinates[8].position[1] = 0.5;
	coordinates[8].position[2] = 0.5;
			  
	coordinates[9].position[0] = 0.5;
	coordinates[9].position[1] = 0.5;
	coordinates[9].position[2] = 0.5;
	
	coordinates[10].position[0] = -0.5;
	coordinates[10].position[1] = 0.5;
	coordinates[10].position[2] = 0.5;
	
	coordinates[11].position[0] = -0.5;
	coordinates[11].position[1] = -0.5;
	coordinates[11].position[2] = 0.5;
	
	coordinates[12].position[0] = -0.5;
	coordinates[12].position[1] = 0.5;
	coordinates[12].position[2] = 0.5;
	
	coordinates[13].position[0] = -0.5;
	coordinates[13].position[1] = 0.5;
	coordinates[13].position[2] = -0.5;
	
	coordinates[14].position[0] = -0.5;
	coordinates[14].position[1] = -0.5;
	coordinates[14].position[2] = -0.5;
	
	coordinates[15].position[0] = -0.5;
	coordinates[15].position[1] = -0.5;
	coordinates[15].position[2] = -0.5;
	
	coordinates[16].position[0] = -0.5;
	coordinates[16].position[1] = -0.5;
	coordinates[16].position[2] = 0.5;
	
	coordinates[17].position[0] = -0.5;
	coordinates[17].position[1] = 0.5;
	coordinates[17].position[2] = 0.5;
	
	coordinates[18].position[0] = 0.5;
	coordinates[18].position[1] = 0.5;
	coordinates[18].position[2] = 0.5;
	
	coordinates[19].position[0] = 0.5;
	coordinates[19].position[1] = 0.5;
	coordinates[19].position[2] = -0.5;
	
	coordinates[20].position[0] = 0.5;
	coordinates[20].position[1] = -0.5;
	coordinates[20].position[2] = -0.5;
	
	coordinates[21].position[0] = 0.5;
	coordinates[21].position[1] = -0.5;
	coordinates[21].position[2] = -0.5;
	
	coordinates[22].position[0] = 0.5;
	coordinates[22].position[1] = -0.5;
	coordinates[22].position[2] = 0.5;
	
	coordinates[23].position[0] = 0.5;
	coordinates[23].position[1] = 0.5;
	coordinates[23].position[2] = 0.5;
	
	coordinates[24].position[0] = -0.5;
	coordinates[24].position[1] = -0.5;
	coordinates[24].position[2] = -0.5;
	
	coordinates[25].position[0] = 0.5;
	coordinates[25].position[1] = -0.5;
	coordinates[25].position[2] = -0.5;
	
	coordinates[26].position[0] = 0.5;
	coordinates[26].position[1] = -0.5;
	coordinates[26].position[2] = 0.5;
	
	coordinates[27].position[0] = 0.5;
	coordinates[27].position[1] = -0.5;
	coordinates[27].position[2] = 0.5;
	
	coordinates[28].position[0] = -0.5;
	coordinates[28].position[1] = -0.5;
	coordinates[28].position[2] = 0.5;
	
	coordinates[29].position[0] = -0.5;
	coordinates[29].position[1] = -0.5;
	coordinates[29].position[2] = -0.5;
			  
	coordinates[30].position[0] = -0.5;
	coordinates[30].position[1] = 0.5;
	coordinates[30].position[2] = -0.5;
			  
	coordinates[31].position[0] = 0.5;
	coordinates[31].position[1] = 0.5;
	coordinates[31].position[2] = -0.5;
	
	coordinates[32].position[0] = 0.5;
	coordinates[32].position[1] = 0.5;
	coordinates[32].position[2] = 0.5;
			  
	coordinates[33].position[0] = 0.5;
	coordinates[33].position[1] = 0.5;
	coordinates[33].position[2] = 0.5;
	
	coordinates[34].position[0] = -0.5;
	coordinates[34].position[1] = 0.5;
	coordinates[34].position[2] = 0.5;
			  
	coordinates[35].position[0] = -0.5;
	coordinates[35].position[1] = 0.5;
	coordinates[35].position[2] = -0.5;

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

void cube::render_cube()
{
	render();
	buff_handle();
}

void cube::draw()
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