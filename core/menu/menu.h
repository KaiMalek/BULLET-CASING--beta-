#pragma once
#include <string>

#include <d3d9.h>
#include "../../dependencies/imgui/imgui.h"
#include "../../dependencies/imgui/imgui_internal.h"

namespace menu {
	void init(LPDIRECT3DDEVICE9);
	void render();
	void infopanel();
	void CustomColorPicker(const char* name, float* color, bool alpha);

	inline LPDIRECT3DDEVICE9 dev;
	inline const char* window_title = "bullet casing";
}
