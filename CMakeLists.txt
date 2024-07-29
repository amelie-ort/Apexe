
cmake_minimum_required (VERSION 3.8)

project ("Apexe")


find_package(Qt6 REQUIRED 
	COMPONENTS Widgets Gui Core Charts
)

# Active l'automatisation de la moc pour les fichiers C++ - MOC (Meta-Object Compiler)
set(CMAKE_AUTOMOC ON)
# Active l'automatisation de l'uic pour les fichiers .ui - les interfaces utilisateur creees avec Qt Designer
set(CMAKE_AUTOUIC ON)
# Active l'automatisation du rcc pour les fichiers .qrc - des fichiers de ressources Qt
set(CMAKE_AUTORCC ON)

set(UI_FILES
    "sources/welcome_page/WelcomePage.ui"
    "sources/game_page/GamePage.ui"
    "sources/sort_page/SortPage.ui"
    "sources/sort_page/BankPage.ui"
)

qt6_wrap_ui(UI_HEADERS ${UI_FILES})

message(STATUS "UI_HEADERS: ${UI_HEADERS}")

add_executable (Apexe 
	${UI_HEADERS}
	"resources.qrc"
	"util/style/applyStyleSheet.h"
	"util/style/applyStyleSheet.cpp"
	"util/widgets/widgets.h"
	"util/widgets/widgets.cpp"
	"util/parserFile/ParserFile.h" 
	"util/parserFile/ParserFile.cpp"
	"sources/Apexe.h" 
	"sources/Apexe.cpp" 
	"sources/main_window/MainWindow.h" 
	"sources/main_window/MainWindow.cpp" 
	"sources/welcome_page/WelcomePage.h"
	"sources/welcome_page/WelcomePage.cpp" 
	"sources/game_page/GamePage.h"
	"sources/game_page/GamePage.cpp" 
	"sources/game_page/sources/RockPaperScissors.h"
	"sources/game_page/sources/RockPaperScissors.cpp"
	"sources/sort_page/sortPage.h"
	"sources/sort_page/sortPage.cpp"
	"sources/sort_page/sources/sort/Sort.h" 
	"sources/sort_page/sources/sort/Sort.cpp" 
	"sources/sort_page/sources/insertion_sort/InsertionSort.h" 
	"sources/sort_page/sources/insertion_sort/InsertionSort.cpp" 
	"sources/sort_page/sources/selection_sort/SelectionSort.h" 
	"sources/sort_page/sources/selection_sort/SelectionSort.cpp"
	"sources/sort_page/CreateSortWidget.cpp" 
	"sources/page/Page.cpp"
	"sources/page/Page.h" 
	"sources/sort_page/sources/bubble_sort/BubbleSort.h" 
	"sources/sort_page/sources/bubble_sort/BubbleSort.cpp" 
	"sources/sort_page/sources/quick_sort/QuickSort.h" 
	"sources/sort_page/sources/quick_sort/QuickSort.cpp"
	"sources/sort_page/sources/merge_sort/MergeSort.h" 
	"sources/sort_page/sources/merge_sort/MergeSort.cpp" 
	"sources/bank_page/BankPage.h" 
	"sources/bank_page/BankPage.cpp" 
	"sources/bank_page/source/bank/Bank.h" 
	"sources/bank_page/source/bank/Bank.cpp" 
	"sources/bank_page/source/bank_account/BankAccount.h" 
	"sources/bank_page/source/bank_account/BankAccount.cpp" 
	"sources/bank_page/source/transaction/Transaction.h" 
	"sources/bank_page/source/transaction/Transaction.cpp" 
	"sources/bank_page/source/transaction_generator/TransactionGenerator.h" 
	"sources/bank_page/source/transaction_generator/TransactionGenerator.cpp"
)

message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

# Ajoutez le repertoire de generation aux chemins d'inclusion
target_include_directories(Apexe PRIVATE
    ${CMAKE_BINARY_DIR}
    ${CMAKE_BINARY_DIR}/Apexe_autogen/include
    ${CMAKE_BINARY_DIR}/CMakeFiles/Apexe_autogen.dir
)


# Activez Rechargement à chaud pour les compilateurs MSVC si cela est pris en charge.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

if (MSVC)
    # Activer l'option "Base de donnees du programme pour Modifier et Continuer (/ZI)"
    target_compile_options(Apexe PRIVATE "/Zi")

    # Desactiver les optimisations pour permettre Modifier et Continuer
    target_compile_options(Apexe PRIVATE "/Od")

    # Activer les informations de debogage
    target_compile_options(Apexe PRIVATE "/DEBUG")

    # Activer le rechargement à chaud dans les paramètres de debogage
    set_property(TARGET Apexe PROPERTY VS_DEBUGGER_ENABLE_EDIT_AND_CONTINUE true)

endif()


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Apexe PROPERTY CXX_STANDARD 20)
else()
  message(WARNING "CMake version is too old to set CXX_STANDARD to 20. Please upgrade CMake.")
endif()

target_link_libraries(Apexe PRIVATE Qt::Widgets Qt::Gui Qt::Core Qt::Charts)