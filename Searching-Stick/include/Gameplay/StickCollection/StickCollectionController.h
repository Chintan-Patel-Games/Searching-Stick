#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>

namespace Gameplay
{
    namespace Collection
    {
        class StickCollectionModel;
        class StickCollectionView;
        enum class SearchType;
        struct Stick;

        class StickCollectionContoller
        {
        private:
            StickCollectionView* collection_view;
            StickCollectionModel* collection_model;

            std::vector<Stick*> sticks;
            Stick* stick_to_search;

            Collection::SearchType search_type;
            std::thread search_thread;

            int number_of_comparisons;
            int number_of_array_access;
            int current_operation_delay;
            int delay_in_ms;
            sf::String time_complexity;

            void initializeSticks();
            float calculateStickWidth();

            void updateSticksPosition();
            void shuffleSticks();
            void sortElements();
            bool compareElementsByData(const Stick* a, const Stick* b) const;

            void resetSticksColor();
            void resetVariables();
            void resetSearchStick();

            void processSearchThreadState();
            void joinThreads();
            void processLinearSearch();
            void processBinarySearch();
            void initializeSticksArray();
            float calculateStickHeight(int array_pos);

            void destroy();

        public:
            StickCollectionContoller();
            ~StickCollectionContoller();

            void initialize();
            void update();
            void render();

            void reset();
            void searchElement(SearchType search_type);

            SearchType getSearchType() const;
            int getNumberOfComparisons() const;
            int getNumberOfArrayAccess() const;
            int getNumberOfSticks() const;
            int getDelayMilliseconds() const;
            sf::String getTimeComplexity() const;
        };
    }
}