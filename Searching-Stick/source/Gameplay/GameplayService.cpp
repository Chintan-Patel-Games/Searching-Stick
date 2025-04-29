#include "Gameplay/GameplayService.h"
#include "Gameplay/GameplayController.h"

namespace Gameplay
{
	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
		collection_controller = new Collection::StickCollectionContoller();
	}

	GameplayService::~GameplayService()
	{
		delete (gameplay_controller);
		delete (collection_controller);
	}

	void GameplayService::initializeRandomSeed()		//helper function for random seed
	{
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
	}

	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
		collection_controller->initialize();
		initializeRandomSeed();		// calling helper function
	}

	void GameplayService::update()
	{
		gameplay_controller->update();
		collection_controller->update();
	}

	void GameplayService::render()
	{
		gameplay_controller->render();
		collection_controller->render();
	}

	void GameplayService::reset()
	{
		gameplay_controller->reset();
		collection_controller->reset();
	}

	void GameplayService::searchElement(Collection::SearchType search_type) { collection_controller->searchElement(search_type); }

	Collection::SearchType GameplayService::getCurrentSearchType() const { return collection_controller->getSearchType(); }

	int GameplayService::getNumberOfComparisons() const { return collection_controller->getNumberOfComparisons(); }

	int GameplayService::getNumberOfArrayAccess() const { return collection_controller->getNumberOfArrayAccess(); }

	int GameplayService::getNumberOfSticks() const { return collection_controller->getNumberOfSticks(); }

	int GameplayService::getDelayMilliseconds() const { return collection_controller->getDelayMilliseconds(); }
}