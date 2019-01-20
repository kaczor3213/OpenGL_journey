#include "../include/rubicCube.hpp"

RubicCube::RubicCube() {
	set_cubes();
	set_inner_covers();
	set_colors();
	set_relations();
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
	for (unsigned i=0; i<cubes.size();i++)	{
		cubes[i].move(tmp[k], tmp[k + 1], tmp[k + 2]);
		k += 3;
	}
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
	process_rubic_keyboard(rubic_keyboard_callback(window), 0.005f);
}

void RubicCube::set_colors() {
	//COVERS
	for (auto &cover : covers)
		cover.set_shape_color(COLOR_BLACK);

	//UP-WHITE
	for (unsigned i = 0; i < 9; i++) {
		for (unsigned j = 30; j < 36; j++)
			cubes[i].coordinates[j].set_color(COLOR_WHITE);
	}

	//DOWN-YELLOW
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

void RubicCube::set_inner_covers() {
	std::vector<Point> tmp = load_from_file("covers.txt");
	covers.resize(6);
	//UP
	for (unsigned i = 0; i < 4; i++)
		covers[0].coordinates[i]=tmp[i];
	//DOWN
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

void RubicCube::set_relations() {
	//UP
	for (unsigned i = 0; i < 9; i++) {
		relationGraph[UP].cubesIndices.insert(i);
	}
	
	//DOWN
	for (unsigned i = 17; i < 26; i++) {
		relationGraph[DOWN].cubesIndices.insert(i);
	}

	//FRONT
	for (unsigned i = 0; i < 3; i++) {
		relationGraph[FRONT].cubesIndices.insert(i);
	}
	for (unsigned i = 9; i < 12; i++) {
		relationGraph[FRONT].cubesIndices.insert(i);
	}
	for (unsigned i = 17; i < 20; i++) {
		relationGraph[FRONT].cubesIndices.insert(i);
	}

	//BACK
	for (unsigned i = 6; i < 9; i++) {
		relationGraph[BACK].cubesIndices.insert(i);
	}
	for (unsigned i = 14; i < 17; i++) {
		relationGraph[BACK].cubesIndices.insert(i);
	}
	for (unsigned i = 23; i < 26; i++) {
		relationGraph[BACK].cubesIndices.insert(i);
	}

	//LEFTS
	for (unsigned i = 0; i < 13; i += 3) {
		relationGraph[LEFTS].cubesIndices.insert(i);
	}
	for (unsigned i = 14; i < 24; i += 3) {
		relationGraph[LEFTS].cubesIndices.insert(i);
	}

	//RIGHTS
	for (unsigned i = 2; i < 12; i += 3) {
		relationGraph[RIGHTS].cubesIndices.insert(i);
	}
	for (unsigned i = 13; i < 26; i += 3) {
		relationGraph[RIGHTS].cubesIndices.insert(i);
	}
}



std::pair<Face, Way> RubicCube::rubic_keyboard_callback(GLFWwindow *window) {
	//CLOSE_WINDOW
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	//UP+CLOCKWISE
	if (glfwGetKey(window, GLFW_KEY_KP_8) == GLFW_PRESS)
		return std::make_pair(UP,CLOCKWISE);
	//DOWN+CLOCKWISE
	if (glfwGetKey(window, GLFW_KEY_KP_2) == GLFW_PRESS)
		return std::make_pair(DOWN, CLOCKWISE);
	//FRONT+CLOCKWISE
	if (glfwGetKey(window, GLFW_KEY_KP_7) == GLFW_PRESS)
		return std::make_pair(FRONT, CLOCKWISE);
	//BACK+CLOCKWISE
	if (glfwGetKey(window, GLFW_KEY_KP_1) == GLFW_PRESS)
		return std::make_pair(BACK, CLOCKWISE);
	//LEFTS+CLOCKWISE
	if (glfwGetKey(window, GLFW_KEY_KP_4) == GLFW_PRESS)
		return std::make_pair(LEFTS, CLOCKWISE);
	//RIGHTS+CLOCKWISE
	if (glfwGetKey(window, GLFW_KEY_KP_6) == GLFW_PRESS)
		return std::make_pair(RIGHTS, CLOCKWISE);

	//UP+ANTICLOCKWISE
	if (glfwGetKey(window, GLFW_KEY_KP_8) == GLFW_PRESS &&
		glfwGetKey(window, GLFW_KEY_KP_0) == GLFW_PRESS)
		return std::make_pair(UP, ANTICLOCKWISE);
	//DOWN+ANTICLOCKWISE
	if (glfwGetKey(window, GLFW_KEY_KP_2) == GLFW_PRESS &&
		glfwGetKey(window, GLFW_KEY_KP_0) == GLFW_PRESS)
		return std::make_pair(DOWN, ANTICLOCKWISE);
	//FRONT+ANTICLOCKWISE
	if (glfwGetKey(window, GLFW_KEY_KP_7) == GLFW_PRESS &&
		glfwGetKey(window, GLFW_KEY_KP_0) == GLFW_PRESS)
		return std::make_pair(FRONT, ANTICLOCKWISE);
	//BACK+ANTICLOCKWISE
	if (glfwGetKey(window, GLFW_KEY_KP_1) == GLFW_PRESS &&
		glfwGetKey(window, GLFW_KEY_KP_0) == GLFW_PRESS)
		return std::make_pair(BACK, ANTICLOCKWISE);
	//LEFTS+ANTICLOCKWISE
	if (glfwGetKey(window, GLFW_KEY_KP_4) == GLFW_PRESS &&
		glfwGetKey(window, GLFW_KEY_KP_0) == GLFW_PRESS)
		return std::make_pair(LEFTS, ANTICLOCKWISE);
	//RIGHTS+ANTICLOCKWISE
	if (glfwGetKey(window, GLFW_KEY_KP_6) == GLFW_PRESS &&
		glfwGetKey(window, GLFW_KEY_KP_0) == GLFW_PRESS)
		return std::make_pair(RIGHTS, ANTICLOCKWISE);
	return std::make_pair(NOFACE,NOWAY);
}

unsigned corelations(const unsigned &ind, const std::map<Face, Side> &relations) {
	unsigned tmp{};
	for (const auto side : relations)
		for (const auto otherInd : side.second.cubesIndices)
			if (ind == otherInd) tmp++;
	return tmp;
}



void RubicCube::animate_side(std::pair<Face, Way> move) {
	if (move.second == CLOCKWISE) {
		//UP+CLOCKWISE
		if (move.first == UP) {
			cubes[4].rotate(1.57f, 0.0f, -1.0f, 0.0f);
			


		}
		//DOWN+CLOCKWISE
		if (move.first == DOWN) {
			cubes[21].rotate(1.57f, 0.0f, 1.0f, 0.0f);
		}
		//FRONT+CLOCKWISE
		if (move.first == FRONT) {
			
			for (auto indice : relationGraph[FRONT].cubesIndices)
			{
				switch (corelations(indice,relationGraph))
				{
				case 1:
					cubes[indice].rotate(1.57f, 0.0f, 0.0f, -1.0f);
					break;
				case 2:
					cubes[indice].rotate(1.57f, 0.0f, 0.0f, -1.0f);
					break;
				case 3:
					cubes[indice].rotate(1.57f, 0.0f, 0.0f, -1.0f);
					break;
				}
			}
		}
		//BACK+CLOCKWISE
		if (move.first == BACK) {
			cubes[15].rotate(1.57f, 0.0f, 0.0f, 1.0f);
		}
		//LEFTS+CLOCKWISE
		if (move.first == LEFTS) {
			cubes[12].rotate(1.57f, 1.0f, 0.0f, 0.0f);
		}
		//RIGHTS+CLOCKWISE
		if (move.first == RIGHTS) {
			cubes[13].rotate(1.57f, -1.0f, 0.0f, 0.0f);
		}
	}
	else {
		//UP+ANTICLOCKWISE
		if (move.first == UP) {

		}
		//DOWN+ANTICLOCKWISE
		if (move.first == DOWN) {

		}
		//FRONT+ANTICLOCKWISE
		if (move.first == FRONT) {

		}
		//BACK+ANTICLOCKWISE
		if (move.first == BACK) {

		}
		//LEFTS+ANTICLOCKWISE
		if (move.first == LEFTS) {

		}
		//RIGHTS+ANTICLOCKWISE
		if (move.first == RIGHTS) {

		}
	}
}

void RubicCube::process_rubic_keyboard(std::pair<Face, Way> move, const float &deltaTime) {
	
	animate_side(move);
	if (move.first != NOFACE)	{
		if (move.second == CLOCKWISE) {
			//UP+CLOCKWISE
			if (move.first == UP) {
				
				std::set<unsigned> UL;
				std::set<unsigned> UB;
				std::set<unsigned> UR;
				std::set<unsigned> UF;
				//AFFECTS: LRFB
				for (auto indiceU : relationGraph[UP].cubesIndices) {
					for (auto &indiceF : relationGraph[FRONT].cubesIndices)
						if (indiceU == indiceF) {
							UL.insert(indiceU);
							relationGraph[FRONT].cubesIndices.erase(indiceF);
						}
					for (auto &indiceL : relationGraph[LEFTS].cubesIndices)
						if (indiceU == indiceL) {
							UB.insert(indiceU);
							relationGraph[LEFTS].cubesIndices.erase(indiceL);
						}
					for (auto &indiceB : relationGraph[BACK].cubesIndices)
						if (indiceU == indiceB) {
							UR.insert(indiceU);
							relationGraph[BACK].cubesIndices.erase(indiceB);
						}
					for (auto &indiceR : relationGraph[RIGHTS].cubesIndices)
						if (indiceU == indiceR) {
							UF.insert(indiceU);
							relationGraph[RIGHTS].cubesIndices.erase(indiceR);
						}
				}				
				relationGraph[LEFTS].cubesIndices.insert(UL.begin(), UL.end());
				relationGraph[RIGHTS].cubesIndices.insert(UR.begin(), UR.end());
				relationGraph[FRONT].cubesIndices.insert(UF.begin(), UF.end());
				relationGraph[BACK].cubesIndices.insert(UB.begin(), UB.end());
				for (auto face : relationGraph) {
					for (auto indice : face.second.cubesIndices) {
						std::cout << indice << "\t";
					}
					std::cout << "\n";
				}
			}
			//DOWN+CLOCKWISE
			if (move.first == DOWN) {
				std::set<unsigned> DL;
				std::set<unsigned> DB;
				std::set<unsigned> DR;
				std::set<unsigned> DF;
				//AFFECTS: LRFB
				for (auto indiceD : relationGraph[DOWN].cubesIndices) {
					for (auto &indiceF : relationGraph[FRONT].cubesIndices)
						if (indiceD == indiceF) {
							DR.insert(indiceD);
							relationGraph[FRONT].cubesIndices.erase(indiceF);
						}
					for (auto &indiceL : relationGraph[LEFTS].cubesIndices)
						if (indiceD == indiceL) {
							DF.insert(indiceD);
							relationGraph[LEFTS].cubesIndices.erase(indiceL);
						}
					for (auto &indiceB : relationGraph[BACK].cubesIndices)
						if (indiceD == indiceB) {
							DL.insert(indiceD);
							relationGraph[BACK].cubesIndices.erase(indiceB);
						}
					for (auto &indiceR : relationGraph[RIGHTS].cubesIndices)
						if (indiceD == indiceR) {
							DB.insert(indiceD);
							relationGraph[RIGHTS].cubesIndices.erase(indiceR);
						}
				}
				relationGraph[LEFTS].cubesIndices.insert(DL.begin(), DL.end());
				relationGraph[RIGHTS].cubesIndices.insert(DR.begin(), DR.end());
				relationGraph[FRONT].cubesIndices.insert(DF.begin(), DF.end());
				relationGraph[BACK].cubesIndices.insert(DB.begin(), DB.end());
				for (auto face : relationGraph) {
					for (auto indice : face.second.cubesIndices) {
						std::cout << indice << "\t";
					}
					std::cout << "\n";
				}
			}
			//FRONT+CLOCKWISE
			if (move.first == FRONT) {
				std::set<unsigned> FL;
				std::set<unsigned> FU;
				std::set<unsigned> FR;
				std::set<unsigned> FD;
				//AFFECTS: UDLR
				for (auto indiceF : relationGraph[FRONT].cubesIndices) {
					for (auto &indiceL : relationGraph[LEFTS].cubesIndices)
						if (indiceF == indiceL) {
							FU.insert(indiceF);
							relationGraph[LEFTS].cubesIndices.erase(indiceL);
						}
					for (auto &indiceU : relationGraph[UP].cubesIndices)
						if (indiceF == indiceU) {
							FR.insert(indiceF);
							relationGraph[UP].cubesIndices.erase(indiceU);
						}
					for (auto &indiceR : relationGraph[RIGHTS].cubesIndices)
						if (indiceF == indiceR) {
							FD.insert(indiceF);
							relationGraph[RIGHTS].cubesIndices.erase(indiceR);
						}
					for (auto &indiceD : relationGraph[DOWN].cubesIndices)
						if (indiceF == indiceD) {
							FL.insert(indiceF);
							relationGraph[DOWN].cubesIndices.erase(indiceD);
						}
				}
				relationGraph[LEFTS].cubesIndices.insert(FL.begin(), FL.end());
				relationGraph[UP].cubesIndices.insert(FU.begin(), FU.end());
				relationGraph[RIGHTS].cubesIndices.insert(FR.begin(), FR.end());
				relationGraph[DOWN].cubesIndices.insert(FD.begin(), FD.end());
				for (auto face : relationGraph) {
					for (auto indice : face.second.cubesIndices) {
						std::cout << indice << "\t";
					}
					std::cout << "\n";
				}
			}
			//BACK+CLOCKWISE
			if (move.first == BACK) {
				std::set<unsigned> BL;
				std::set<unsigned> BU;
				std::set<unsigned> BR;
				std::set<unsigned> BD;
				//AFFECTS: UDLR
				for (auto indiceB : relationGraph[BACK].cubesIndices) {
					for (auto &indiceL : relationGraph[LEFTS].cubesIndices)
						if (indiceB == indiceL) {
							BD.insert(indiceB);
							relationGraph[LEFTS].cubesIndices.erase(indiceL);
						}
					for (auto &indiceU : relationGraph[UP].cubesIndices)
						if (indiceB == indiceU) {
							BL.insert(indiceB);
							relationGraph[UP].cubesIndices.erase(indiceU);
						}
					for (auto &indiceR : relationGraph[RIGHTS].cubesIndices)
						if (indiceB == indiceR) {
							BU.insert(indiceB);
							relationGraph[RIGHTS].cubesIndices.erase(indiceR);
						}
					for (auto &indiceD : relationGraph[DOWN].cubesIndices)
						if (indiceB == indiceD) {
							BR.insert(indiceB);
							relationGraph[DOWN].cubesIndices.erase(indiceD);
						}
				}
				relationGraph[LEFTS].cubesIndices.insert(BL.begin(), BL.end());
				relationGraph[UP].cubesIndices.insert(BU.begin(), BU.end());
				relationGraph[RIGHTS].cubesIndices.insert(BR.begin(), BR.end());
				relationGraph[DOWN].cubesIndices.insert(BD.begin(), BD.end());
				for (auto face : relationGraph) {
					for (auto indice : face.second.cubesIndices) {
						std::cout << indice << "\t";
					}
					std::cout << "\n";
				}
			}
			//LEFTS+CLOCKWISE
			if (move.first == LEFTS) {
				std::set<unsigned> LU;
				std::set<unsigned> LF;
				std::set<unsigned> LD;
				std::set<unsigned> LB;
				//AFFECTS: UDFB
				for (auto indiceL : relationGraph[LEFTS].cubesIndices) {
					for (auto &indiceU : relationGraph[UP].cubesIndices)
						if (indiceL == indiceU) {
							LF.insert(indiceL);
							relationGraph[UP].cubesIndices.erase(indiceU);
						}
					for (auto &indiceF : relationGraph[FRONT].cubesIndices)
						if (indiceL == indiceF) {
							LD.insert(indiceL);
							relationGraph[FRONT].cubesIndices.erase(indiceF);
						}
					for (auto &indiceD : relationGraph[DOWN].cubesIndices)
						if (indiceL == indiceD) {
							LB.insert(indiceL);
							relationGraph[DOWN].cubesIndices.erase(indiceD);
						}
					for (auto &indiceB : relationGraph[BACK].cubesIndices)
						if (indiceL == indiceB) {
							LU.insert(indiceL);
							relationGraph[BACK].cubesIndices.erase(indiceB);
						}
				}
				relationGraph[UP].cubesIndices.insert(LU.begin(), LU.end());
				relationGraph[FRONT].cubesIndices.insert(LF.begin(), LF.end());
				relationGraph[DOWN].cubesIndices.insert(LD.begin(), LD.end());
				relationGraph[BACK].cubesIndices.insert(LB.begin(), LB.end());
				for (auto face : relationGraph) {
					for (auto indice : face.second.cubesIndices) {
						std::cout << indice << "\t";
					}
					std::cout << "\n";
				}
			}
			//RIGHTS+CLOCKWISE
			if (move.first == RIGHTS) {
				std::set<unsigned> RU;
				std::set<unsigned> RF;
				std::set<unsigned> RD;
				std::set<unsigned> RB;
				//AFFECTS: UDFB
				for (auto indiceL : relationGraph[LEFTS].cubesIndices) {
					for (auto &indiceU : relationGraph[UP].cubesIndices)
						if (indiceL == indiceU) {
							RB.insert(indiceL);
							relationGraph[UP].cubesIndices.erase(indiceU);
						}
					for (auto &indiceF : relationGraph[FRONT].cubesIndices)
						if (indiceL == indiceF) {
							RU.insert(indiceL);
							relationGraph[FRONT].cubesIndices.erase(indiceF);
						}
					for (auto &indiceD : relationGraph[DOWN].cubesIndices)
						if (indiceL == indiceD) {
							RF.insert(indiceL);
							relationGraph[DOWN].cubesIndices.erase(indiceD);
						}
					for (auto &indiceB : relationGraph[BACK].cubesIndices)
						if (indiceL == indiceB) {
							RD.insert(indiceL);
							relationGraph[BACK].cubesIndices.erase(indiceB);
						}
				}
				relationGraph[UP].cubesIndices.insert(RU.begin(), RU.end());
				relationGraph[FRONT].cubesIndices.insert(RF.begin(), RF.end());
				relationGraph[DOWN].cubesIndices.insert(RD.begin(), RD.end());
				relationGraph[BACK].cubesIndices.insert(RB.begin(), RB.end());
				for (auto face : relationGraph) {
					for (auto indice : face.second.cubesIndices) {
						std::cout << indice << "\t";
					}
					std::cout << "\n";
				}
			}
		}
		else {///////////////////////////////////////////////////////////////////////
			//UP+ANTICLOCKWISE
			if (move.first == UP) {
				std::set<unsigned> UL;
				std::set<unsigned> UB;
				std::set<unsigned> UR;
				std::set<unsigned> UF;
				//AFFECTS: LRFB
				for (auto indiceU : relationGraph[UP].cubesIndices) {
					for (auto &indiceF : relationGraph[FRONT].cubesIndices)
						if (indiceU == indiceF) {
							UR.insert(indiceU);
							relationGraph[FRONT].cubesIndices.erase(indiceF);
						}
					for (auto &indiceL : relationGraph[LEFTS].cubesIndices)
						if (indiceU == indiceL) {
							UF.insert(indiceU);
							relationGraph[LEFTS].cubesIndices.erase(indiceL);
						}
					for (auto &indiceB : relationGraph[BACK].cubesIndices)
						if (indiceU == indiceB) {
							UL.insert(indiceU);
							relationGraph[BACK].cubesIndices.erase(indiceB);
						}
					for (auto &indiceR : relationGraph[RIGHTS].cubesIndices)
						if (indiceU == indiceR) {
							UB.insert(indiceU);
							relationGraph[RIGHTS].cubesIndices.erase(indiceR);
						}
				}
				relationGraph[LEFTS].cubesIndices.insert(UL.begin(), UL.end());
				relationGraph[RIGHTS].cubesIndices.insert(UR.begin(), UR.end());
				relationGraph[FRONT].cubesIndices.insert(UF.begin(), UF.end());
				relationGraph[BACK].cubesIndices.insert(UB.begin(), UB.end());
				for (auto face : relationGraph) {
					for (auto indice : face.second.cubesIndices) {
						std::cout << indice << "\t";
					}
					std::cout << "\n";
				}
			}
			//DOWN+ANTICLOCKWISE
			if (move.first == DOWN) {
				std::set<unsigned> DL;
				std::set<unsigned> DB;
				std::set<unsigned> DR;
				std::set<unsigned> DF;
				//AFFECTS: LRFB
				for (auto indiceD : relationGraph[DOWN].cubesIndices) {
					for (auto &indiceF : relationGraph[FRONT].cubesIndices)
						if (indiceD == indiceF) {
							DL.insert(indiceD);
							relationGraph[FRONT].cubesIndices.erase(indiceF);
						}
					for (auto &indiceL : relationGraph[LEFTS].cubesIndices)
						if (indiceD == indiceL) {
							DB.insert(indiceD);
							relationGraph[LEFTS].cubesIndices.erase(indiceL);
						}
					for (auto &indiceB : relationGraph[BACK].cubesIndices)
						if (indiceD == indiceB) {
							DR.insert(indiceD);
							relationGraph[BACK].cubesIndices.erase(indiceB);
						}
					for (auto &indiceR : relationGraph[RIGHTS].cubesIndices)
						if (indiceD == indiceR) {
							DF.insert(indiceD);
							relationGraph[RIGHTS].cubesIndices.erase(indiceR);
						}
				}
				relationGraph[LEFTS].cubesIndices.insert(DL.begin(), DL.end());
				relationGraph[RIGHTS].cubesIndices.insert(DR.begin(), DR.end());
				relationGraph[FRONT].cubesIndices.insert(DF.begin(), DF.end());
				relationGraph[BACK].cubesIndices.insert(DB.begin(), DB.end());
				for (auto face : relationGraph) {
					for (auto indice : face.second.cubesIndices) {
						std::cout << indice << "\t";
					}
					std::cout << "\n";
				}
			}
			//FRONT+ANTICLOCKWISE
			if (move.first == FRONT) {
				std::set<unsigned> FL;
				std::set<unsigned> FU;
				std::set<unsigned> FR;
				std::set<unsigned> FD;
				//AFFECTS: UDLR
				for (auto indiceF : relationGraph[FRONT].cubesIndices) {
					for (auto &indiceL : relationGraph[LEFTS].cubesIndices)
						if (indiceF == indiceL) {
							FD.insert(indiceF);
							relationGraph[LEFTS].cubesIndices.erase(indiceL);
						}
					for (auto &indiceU : relationGraph[UP].cubesIndices)
						if (indiceF == indiceU) {
							FL.insert(indiceF);
							relationGraph[UP].cubesIndices.erase(indiceU);
						}
					for (auto &indiceR : relationGraph[RIGHTS].cubesIndices)
						if (indiceF == indiceR) {
							FU.insert(indiceF);
							relationGraph[RIGHTS].cubesIndices.erase(indiceR);
						}
					for (auto &indiceD : relationGraph[DOWN].cubesIndices)
						if (indiceF == indiceD) {
							FR.insert(indiceF);
							relationGraph[DOWN].cubesIndices.erase(indiceD);
						}
				}
				relationGraph[LEFTS].cubesIndices.insert(FL.begin(), FL.end());
				relationGraph[UP].cubesIndices.insert(FU.begin(), FU.end());
				relationGraph[RIGHTS].cubesIndices.insert(FR.begin(), FR.end());
				relationGraph[DOWN].cubesIndices.insert(FD.begin(), FD.end());
				for (auto face : relationGraph) {
					for (auto indice : face.second.cubesIndices) {
						std::cout << indice << "\t";
					}
					std::cout << "\n";
				}
			}
			//BACK+ANTICLOCKWISE
			if (move.first == BACK) {
				std::set<unsigned> BL;
				std::set<unsigned> BU;
				std::set<unsigned> BR;
				std::set<unsigned> BD;
				//AFFECTS: UDLR
				for (auto indiceB : relationGraph[BACK].cubesIndices) {
					for (auto &indiceL : relationGraph[LEFTS].cubesIndices)
						if (indiceB == indiceL) {
							BU.insert(indiceB);
							relationGraph[LEFTS].cubesIndices.erase(indiceL);
						}
					for (auto &indiceU : relationGraph[UP].cubesIndices)
						if (indiceB == indiceU) {
							BR.insert(indiceB);
							relationGraph[UP].cubesIndices.erase(indiceU);
						}
					for (auto &indiceR : relationGraph[RIGHTS].cubesIndices)
						if (indiceB == indiceR) {
							BD.insert(indiceB);
							relationGraph[RIGHTS].cubesIndices.erase(indiceR);
						}
					for (auto &indiceD : relationGraph[DOWN].cubesIndices)
						if (indiceB == indiceD) {
							BL.insert(indiceB);
							relationGraph[DOWN].cubesIndices.erase(indiceD);
						}
				}
				relationGraph[LEFTS].cubesIndices.insert(BL.begin(), BL.end());
				relationGraph[UP].cubesIndices.insert(BU.begin(), BU.end());
				relationGraph[RIGHTS].cubesIndices.insert(BR.begin(), BR.end());
				relationGraph[DOWN].cubesIndices.insert(BD.begin(), BD.end());
				for (auto face : relationGraph) {
					for (auto indice : face.second.cubesIndices) {
						std::cout << indice << "\t";
					}
					std::cout << "\n";
				}
			}
			//LEFTS+ANTICLOCKWISE
			if (move.first == LEFTS) {
				std::set<unsigned> LU;
				std::set<unsigned> LF;
				std::set<unsigned> LD;
				std::set<unsigned> LB;
				//AFFECTS: UDFB
				for (auto indiceL : relationGraph[LEFTS].cubesIndices) {
					for (auto &indiceU : relationGraph[UP].cubesIndices)
						if (indiceL == indiceU) {
							LB.insert(indiceL);
							relationGraph[UP].cubesIndices.erase(indiceU);
						}
					for (auto &indiceF : relationGraph[FRONT].cubesIndices)
						if (indiceL == indiceF) {
							LU.insert(indiceL);
							relationGraph[FRONT].cubesIndices.erase(indiceF);
						}
					for (auto &indiceD : relationGraph[DOWN].cubesIndices)
						if (indiceL == indiceD) {
							LF.insert(indiceL);
							relationGraph[DOWN].cubesIndices.erase(indiceD);
						}
					for (auto &indiceB : relationGraph[BACK].cubesIndices)
						if (indiceL == indiceB) {
							LD.insert(indiceL);
							relationGraph[BACK].cubesIndices.erase(indiceB);
						}
				}
				relationGraph[UP].cubesIndices.insert(LU.begin(), LU.end());
				relationGraph[FRONT].cubesIndices.insert(LF.begin(), LF.end());
				relationGraph[DOWN].cubesIndices.insert(LD.begin(), LD.end());
				relationGraph[BACK].cubesIndices.insert(LB.begin(), LB.end());
				for (auto face : relationGraph) {
					for (auto indice : face.second.cubesIndices) {
						std::cout << indice << "\t";
					}
					std::cout << "\n";
				}
			}
			//RIGHTS+ANTICLOCKWISE
			if (move.first == RIGHTS) {
				std::set<unsigned> RU;
				std::set<unsigned> RF;
				std::set<unsigned> RD;
				std::set<unsigned> RB;
				//AFFECTS: UDFB
				for (auto indiceL : relationGraph[LEFTS].cubesIndices) {
					for (auto &indiceU : relationGraph[UP].cubesIndices)
						if (indiceL == indiceU) {
							RF.insert(indiceL);
							relationGraph[UP].cubesIndices.erase(indiceU);
						}
					for (auto &indiceF : relationGraph[FRONT].cubesIndices)
						if (indiceL == indiceF) {
							RD.insert(indiceL);
							relationGraph[FRONT].cubesIndices.erase(indiceF);
						}
					for (auto &indiceD : relationGraph[DOWN].cubesIndices)
						if (indiceL == indiceD) {
							RB.insert(indiceL);
							relationGraph[DOWN].cubesIndices.erase(indiceD);
						}
					for (auto &indiceB : relationGraph[BACK].cubesIndices)
						if (indiceL == indiceB) {
							RU.insert(indiceL);
							relationGraph[BACK].cubesIndices.erase(indiceB);
						}
				}
				relationGraph[UP].cubesIndices.insert(RU.begin(), RU.end());
				relationGraph[FRONT].cubesIndices.insert(RF.begin(), RF.end());
				relationGraph[DOWN].cubesIndices.insert(RD.begin(), RD.end());
				relationGraph[BACK].cubesIndices.insert(RB.begin(), RB.end());
				for (auto face : relationGraph) {
					for (auto indice : face.second.cubesIndices) {
						std::cout << indice << "\t";
					}
					std::cout << "\n";
				}
			}
		}
	}
}