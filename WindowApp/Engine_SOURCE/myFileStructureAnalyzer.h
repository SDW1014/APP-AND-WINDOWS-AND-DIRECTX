#pragma once
#include "myResource.h"

namespace MyApp
{
	class FileStructureAnalyzer
	{
	public:
		FileStructureAnalyzer() {} // 생성자 구현
		~FileStructureAnalyzer() {} // 소멸자 구현

		// 메인 경로 설정
		void SetMainPath(const std::wstring& path) {
			mainPath = path; // std::string 대신 std::wstring 사용
		}

		// 메인 경로 가져오기
		std::wstring GetMainPath() const { return mainPath; }
		std::vector<std::wstring> GetFileList() const { return fileList; }
		std::vector<std::wstring> GetSubfolderList() const { return subfolderList; }

		// 파일 구조 분석
		void AnalyzeFolderStructure()
		{
			// 파일 검색을 위한 구조체와 핸들 선언
			WIN32_FIND_DATA findFileData; // 파일 정보를 저장하는 구조체
			HANDLE hFind; // 파일 검색 핸들

			// 검색할 경로 설정
			std::wstring searchPath = mainPath + L"\\*";
			hFind = FindFirstFile(searchPath.c_str(), &findFileData);

			// 경로가 유효하지 않으면 종료
			if (hFind == INVALID_HANDLE_VALUE) 
			{
				return; 
			} 

			// 파일 검색 반복
			std::vector<std::wstring> folderQueue; // 서브폴더를 저장할 큐
			folderQueue.push_back(mainPath); // 메인 경로를 큐에 추가

			while (!folderQueue.empty()) 
			{
				std::wstring currentPath = folderQueue.back(); // 큐에서 현재 경로 가져오기
				folderQueue.pop_back(); // 큐에서 현재 경로 제거

				std::wstring searchPath = currentPath + L"\\*"; // 검색할 경로 설정
				hFind = FindFirstFile(searchPath.c_str(), &findFileData);

				if (hFind == INVALID_HANDLE_VALUE) 
				{
					continue; 
				} 

				do 
				{
					// 디렉토리인지 확인
					if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) 
					{
						// 현재 디렉토리와 상위 디렉토리는 제외
						if (wcscmp(findFileData.cFileName, L".") != 0 && wcscmp(findFileData.cFileName, L"..") != 0) 
						{
							std::wstring subfolderPath = currentPath + L"\\" + findFileData.cFileName; // 서브폴더 경로 생성
							subfolderList.push_back(subfolderPath); // 서브폴더 리스트에 추가
							folderQueue.push_back(subfolderPath); // 서브폴더를 큐에 추가
						}
					}
				} 
				while (FindNextFile(hFind, &findFileData) != 0); // 다음 파일 찾기

				FindClose(hFind); // 핸들 닫기
			}
		}
		void AnalyzeFileStructure()
		{
			if (!subfolderList.empty()) // subfolderList가 비어있지 않은 경우에만 실행
			{
				for (const auto& subfolder : subfolderList) 
				{
					std::wstring folderPath = subfolder + L"\\*"; // mainPath를 제거하고 subfolder만 사용
					WIN32_FIND_DATA findFileData;
					HANDLE hFind = FindFirstFile(folderPath.c_str(), &findFileData);

					if (hFind == INVALID_HANDLE_VALUE) 
					{
						continue; 
					}

					do 
					{
						if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) 
						{
							fileList.push_back(subfolder + L"\\" + findFileData.cFileName); // 파일 리스트에 추가할 때 경로를 포함
						}
					} 
					while (FindNextFile(hFind, &findFileData) != 0);

					FindClose(hFind);
				}
			}
		}
	
	private:
		std::wstring mainPath; // 메인 경로
		std::vector<std::wstring> subfolderList; // 서브폴더 리스트
		std::vector<std::wstring> fileList; // 파일 리스트
	};
}