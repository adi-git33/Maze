// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052

#ifndef __CONTROLLER__
#define __CONTROLLER__

#include "Maze2dModel.hpp"
#include "CLI.hpp"
#include "Commands/CommandHashMap.hpp"
#include "Observer.hpp"

using namespace std;

class Controller : public Observer
{
protected:
    Maze2dModel *m_model;
    View *m_view;
    CommandHM *m_commandSet;

public:
    // Constractor
    Controller(Maze2dModel *newModel, View *newView, CommandHM *newCmndHM)
    {
        m_model = newModel;
        m_model->AttachObserver(this);
        m_view = newView;
        m_view->AttachObserver("Controller", this);
        m_commandSet = newCmndHM;
    };
    // Destractor
    ~Controller(){};
    // Operators
    // Getters
    // Setters
    // Functions
    virtual void modelUpdate(string result)
    {
        if (result == "Congrats, you won!")
        {
            m_view->setStatus("Controller", true);
        }
        m_view->PrintResult(result);
    };
    virtual void viewUpdate(string cmd, vector<string> s)
    {
        if (m_commandSet->findCommend(cmd))
        {
            m_commandSet->executeCommand(cmd, s, m_model);
        }
        else
        {
            m_view->PrintResult("Command not found.");
        }
    };
    virtual void returnStatus(string status)
    {
        bool res = m_model->checkIfExist(status);
        m_view->setStatus("Controller", res);
    };

    void startFunc()
    {
        m_view->Start();
    };
};

#endif