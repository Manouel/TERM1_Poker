SOURCES += \
    src/Interface/main.cpp \
    src/Interface/Logger.cpp \
    src/Game/Action.cpp \
    src/Interface/ContenuFenetreIA.cpp \
    src/Interface/CustomPlot/qcustomplot.cpp \
    src/Assessor/Assessor.cpp \
    src/Assessor/PlayerCards.cpp \
    src/MathematicalFormula/MathematicalFormula.cpp \
    src/Game/Card.cpp \
    src/Profiling/CalculateProfilingData.cpp \
    src/Profiling/GamePhase.cpp \
    src/Profiling/Profile.cpp \
    src/Profiling/Profiling.cpp \
    src/Profiling/TestScenario.cpp \
    src/AI/IdealCalibration.cpp \
    src/AI/WinningChancesEstimator.cpp \
    src/AI/ArtificialIntelligence.cpp \
    src/AI/ArtificialIntelligenceProfiling.cpp \
    src/AI/Resolver.cpp \
    src/Game/HumanPlayer.cpp \
    src/Game/Player.cpp \
    src/Game/Game.cpp \
    src/Interface/GraphicCard.cpp \
    src/Interface/ClickableCard.cpp \
    src/Interface/TokensCounter.cpp \
    src/Interface/CardsDialog.cpp \
    src/Interface/CardsList.cpp \
    src/Interface/CalibrationChoice.cpp \
    src/Interface/OptionsDialog.cpp \
    src/Interface/Window.cpp \
    src/Interface/WindowContent.cpp \
    src/Interface/HumanWindowContent.cpp


QT+=widgets printsupport

HEADERS += \
    include/Constantes.h \
    include/Interface/Logger.h \
    include/Game/Action.h \
    include/Interface/ContenuFenetreIA.h \
    include/Interface/CustomPlot/qcustomplot.h \
    include/Assessor/Assessor.h \
    include/Assessor/PlayerCards.h \
    include/MathematicalFormula/MathematicalFormula.h \
    include/Game/Card.h \
    include/Profiling/CalculateProfilingData.h \
    include/Profiling/GamePhase.h \
    include/Profiling/Profile.h \
    include/Profiling/Profiling.h \
    include/Profiling/TestScenario.h \
    include/AI/IdealCalibration.h \
    include/AI/WinningChancesEstimator.h \
    include/AI/ArtificialIntelligence.h \
    include/AI/ArtificialIntelligenceProfiling.h \
    include/AI/Resolver.h \
    include/Game/Player.h \
    include/Game/Game.h \
    include/Interface/GraphicCard.h \
    include/Interface/ClickableCard.h \
    include/Interface/TokensCounter.h \
    include/Interface/CardsDialog.h \
    include/Interface/CardsList.h \
    include/Interface/CalibrationChoice.h \
    include/Interface/OptionsDialog.h \
    include/Game/HumanPlayer.h \
    include/Interface/Window.h \
    include/Interface/WindowContent.h \
    include/Interface/HumanWindowContent.h

CONFIG += c++14
!win32 {
    QMAKE_CXX = g++-4.9
}
QMAKE_CXXFLAGS += -std=c++14

MOC_DIR = moc_dir
OBJECTS_DIR = obj_dir
