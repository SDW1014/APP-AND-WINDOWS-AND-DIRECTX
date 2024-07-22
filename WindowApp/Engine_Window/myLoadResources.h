#pragma once
#include "..\\Engine_SOURCE\\myResources.h"
#include "..\\Engine_SOURCE\\myTexture.h"
#include "..\\Engine_SOURCE\\myFileStructureAnalyzer.h"

namespace MyApp
{
	void LoadResources()
	{
		MyApp::FileStructureAnalyzer analyzer;	// 객체를 스택에 생성
		analyzer.SetMainPath(L"C:\\Users\\82102\\source\\repos\\2024-07-09\\WindowApp\\Recources"); // 메인 경로 설정
		analyzer.AnalyzeFolderStructure();		// 폴더 구조 분석
		analyzer.AnalyzeFileStructure();		// 파일 구조 분석

		std::vector<std::wstring> fileList = analyzer.GetFileList();

		for (const auto& file : fileList)
		{
			std::wstring fileName = file.substr(file.find_last_of(L"\\") + 1); // 파일 이름 추출
			std::wstring folderPath = file.substr(0, file.find_last_of(L"\\")); // 폴더 경로 추출
			std::wstring folderName = folderPath.substr(folderPath.find_last_of(L"\\") + 1); // 폴더 이름 추출
			std::wstring textureName = folderName + L"_" + fileName.substr(0, fileName.find_last_of(L".")); // [폴더이름_파일이름] 형식으로 생성

			Resources::Load<graphics::Texture>(textureName, file);
		}
	}
}