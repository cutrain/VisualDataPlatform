import React, { Component } from 'react';
import ReactDOM from 'react-dom';
import {Route, IndexRoute, Router, browserHistory, Redirect} from 'react-router';
import Homepage from './Homepage';
import Comp from './Comp';
import Layout from './Layout';
import HTML5Backend from 'react-dnd-html5-backend';
import { DragDropContext } from 'react-dnd';

class Main extends Component {
  constructor() {
    super();
  }
  render() {
    return (
      <Router history={browserHistory}>
        <Route path='/' component={Layout}>
          <IndexRoute component={Homepage} />
          <Route path='/component' component={Comp} />
          <Redirect path="*" to="/" />
        </Route>
      </Router>
    );
  }
}

export default DragDropContext(HTML5Backend)(Main);
