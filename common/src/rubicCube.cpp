#include "../include/rubicCube.hpp"

RubicCube::RubicCube()
{
	set_cubes();
	set_inner_covers();
	set_colors();
	//set_inner_covers();
	//set_relations();
}

void RubicCube::set_cubes() {
	cubes.resize(26);
	for (auto &cube : cubes)
		cube.coordinates = load_from_file("cube.txt");
	//for (const auto &cube : cubes) {
	//	coordinates.reserve(coordinates.size() + cube.coordinates.size());
	//	coordinates.insert(std::end(coordinates), std::begin(cube.coordinates), std::end(cube.coordinates));
	//}
	std::vector<float> tmp = load_animation("positions.txt");
	unsigned k = 0;
	for (unsigned i=0; i<cubes.size();i++)
	{
		cubes[i].move(tmp[k], tmp[k + 1], tmp[k + 2]);
		k += 3;
	}
}

void RubicCube::set_sides() {
	for (auto &side : relationGraph)
		side.second.cubesIndices.resize(9);
}

void RubicCube::render() {
	data_parser();
	buff_handle();
	for (auto &cover : covers)
		cover.render();
	for (auto &cube : cubes)
		cube.render();

}

void RubicCube::draw() {
	for (auto &cover : covers)
		cover.draw();
	for (auto &cube : cubes)
		cube.draw();
	/*
	run();
	transformLoc = glGetUniformLocation(shaderProgram, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
	viewLoc = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	projectionLoc = glGetUniformLocation(shaderProgram, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
	texture.textureLoc = glGetUniformLocation(shaderProgram, "ourTexture");
	glUniform1i(texture.textureLoc, 0);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	*/
}

void RubicCube::handle_input(GLFWwindow *&window) {
	process_mouse_movement(get_mouse_position(window), true);
	process_mouse_scroll(get_scroll_position());
	process_keyboard(keyboard_callback(window), 0.005f);
	get_view();
	for (auto &cover : covers)
		cover.handle_input(window);
	for (auto &cube : cubes)
		cube.handle_input(window);	
}

void RubicCube::set_colors()
{
	//COVERS
	for (auto &cover : covers)
		cover.set_shape_color(COLOR_BLACK);

	//UP-WHITE
	for (unsigned i = 0; i < 9; i++) {
		for (unsigned j = 30; j < 36; j++)
			cubes[i].coordinates[j].set_color(COLOR_WHITE);
	}

	//BOTTOM-YELLOW
	for (unsigned i = 17; i < 26; i++) {
		for (unsigned j = 24; j < 30; j++)
			cubes[i].coordinates[j].set_color(COLOR_YELLOW);
	}

	//FRONT-BLUE
	for (unsigned i = 0; i < 3; i++) {
		for (unsigned j = 6; j < 12; j++)
			cubes[i].coordinates[j].set_color(COLOR_BLUE);
	}
	for (unsigned i = 9; i < 12; i++) {
		for (unsigned j = 6; j < 12; j++)
			cubes[i].coordinates[j].set_color(COLOR_BLUE);
	}
	for (unsigned i = 17; i < 20; i++) {
		for (unsigned j = 6; j < 12; j++)
			cubes[i].coordinates[j].set_color(COLOR_BLUE);
	}

	//BACK-GREEN
	for (unsigned i = 6; i < 9; i++) {
		for (unsigned j = 0; j < 6; j++)
			cubes[i].coordinates[j].set_color(COLOR_GREEN);
	}
	for (unsigned i = 14; i < 17; i++) {
		for (unsigned j = 0; j < 6; j++)
			cubes[i].coordinates[j].set_color(COLOR_GREEN);
	}
	for (unsigned i = 23; i < 26; i++) {
		for (unsigned j = 0; j < 6; j++)
			cubes[i].coordinates[j].set_color(COLOR_GREEN);
	}

	//LEFTS-ORANGE
	for (unsigned i = 0; i < 13; i+=3) {
		for (unsigned j = 12; j < 18; j++)
			cubes[i].coordinates[j].set_color(COLOR_ORANGE);
	}
	for (unsigned i = 14; i < 24; i += 3) {
		for (unsigned j = 12; j < 18; j++)
			cubes[i].coordinates[j].set_color(COLOR_ORANGE);
	}

	//RIGHTS-RED
	for (unsigned i = 2; i < 12; i+=3) {
		for (unsigned j = 18; j < 24; j++)
			cubes[i].coordinates[j].set_color(COLOR_RED);
	}
	for (unsigned i = 13; i < 26; i += 3) {
		for (unsigned j = 18; j < 24; j++)
			cubes[i].coordinates[j].set_color(COLOR_RED);
	}
}

void RubicCube::set_inner_covers()
{
	std::vector<Point> tmp = load_from_file("covers.txt");
	covers.resize(6);
	//for (auto &cover : covers)
	//	cover.coordinates.clear();

	//UP
	for (unsigned i = 0; i < 4; i++)
		covers[0].coordinates[i]=tmp[i];
	//BOTTOM
	for (unsigned i = 4; i < 8; i++)
		covers[1].coordinates[i-4] = tmp[i];
	//FRONT
	for (unsigned i = 8; i < 12; i++)
		covers[2].coordinates[i-8] = tmp[i];
	//BACK
	for (unsigned i = 12; i < 16; i++)
		covers[3].coordinates[i-12] = tmp[i];
	//LEFTS
	for (unsigned i = 16; i < 20; i++)
		covers[4].coordinates[i-16] = tmp[i];
	//RIGHTS
	for (unsigned i = 20; i < 24; i++)
		covers[5].coordinates[i-20] = tmp[i];
}