/*
 *	 Copyright (C) 2018 Qub³d Engine Group.
 *	 All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without modification,
 *  are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice, this
 *  list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *  this list of conditions and the following disclaimer in the documentation and/or
 *  other materials provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its contributors
 *  may be used to endorse or promote products derived from this software without
 *  specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 *  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include "globalVars.hpp"
#include <imgui.h>
#include <SDL_events.h>
#include <examples/imgui_impl_sdl.h>
#include <examples/imgui_impl_opengl2.h>

class ImGuiHelper
{
public:
    static void init(ImGuiIO& io)
    {
        // ImGui Bindings
        IMGUI_CHECKVERSION( );
        ImGui::CreateContext( );
        io = ImGui::GetIO( );
        ImGui_ImplSDL2_InitForOpenGL( g_Client->getWindow( ), g_Client->getGLContext( ) );
        ImGui_ImplOpenGL2_Init( );
    }

    static void quit()
    {
        ImGui_ImplOpenGL2_Shutdown( );
        ImGui_ImplSDL2_Shutdown( );
        ImGui::DestroyContext( );
    }

    static void prepareDraw(ImGuiIO& io)
    {
        ImGui::Render( );
        glViewport( 0, 0, static_cast<int>(io.DisplaySize.x), static_cast<int>(io.DisplaySize.y) );
    }

    static void draw()
    {
        ImGui_ImplOpenGL2_RenderDrawData( ImGui::GetDrawData( ) );
    }

    static void updateFrame()
    {
        ImGui_ImplOpenGL2_NewFrame( );
        ImGui_ImplSDL2_NewFrame( g_Client->getWindow( ) );
        ImGui::NewFrame( );
    }

    static void handleEvents(SDL_Event& event)
    {
        ImGui_ImplSDL2_ProcessEvent( &event );
    }
};
